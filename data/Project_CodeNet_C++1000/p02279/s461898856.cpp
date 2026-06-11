#include<bits/stdc++.h>

using namespace std;

typedef struct node_{
    int id;
    int k;
    vector<node_*> children;
    int depth;
    int parent;
}* node;

void printTree(vector<node> tree, int n){
    for(int i = 0; i < n; i++){
        node nd = tree[i];
        char* kind = new char[15];
        if(nd -> parent == -1){
            strcpy(kind, "root");
        }else if(nd -> k == 0){
            strcpy(kind, "leaf");
        }else{
            strcpy(kind, "internal node");
        }
        printf("node %d: parent = %d, depth = %d, %s, ", nd -> id, nd -> parent, nd -> depth, kind);
        printf("[");
        for(int j = 0; j < nd -> k - 1; j++){
            printf("%d, ", nd -> children[j] -> id);
        }
        if(nd -> k != 0){
            printf("%d", nd -> children[nd -> k - 1] -> id);
        }
        printf("]\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<node> tree(n);
    for(int i = 0; i < n; i++){
        node nd = new node_;
        tree[i] = nd;
    }
    vector<int> find_parent(n);
    for(int i = 0; i < n; i++){
        find_parent[i] = 1;
    }
    for(int i = 0; i < n; i++){
        int id, k;
        scanf("%d %d", &id, &k);
        node nd = tree[id];
        nd -> id = id;
        nd -> k = k;
        nd -> parent = -1;
        for(int j = 0; j < k; j++){
            int c;
            scanf("%d", &c);
            nd -> children.push_back(tree[c]);
            find_parent[c] = 0;
        }
    }//各nodeの情報はできた
    int pa = 0;
    int p = find_parent[pa];
    while(p == 0){
        pa++;
        p = find_parent[pa];
    }

    queue<node> Q;
    Q.push(tree[pa]);
    tree[pa] -> depth = 0;
    while(Q.empty() == 0){
        node nd = Q.front();
        Q.pop();
        for(int i = 0; i < nd -> k; i++){
            Q.push(nd -> children[i]);
            nd -> children[i] -> depth = nd -> depth + 1;
            nd -> children[i] -> parent = nd -> id;
        }
    }

    printTree(tree, n);
    return 0;
}
