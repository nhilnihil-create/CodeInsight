#include<iostream>
#include<cstdio>
#include<algorithm>

#define NIL -1

using namespace std;

typedef struct {int parent,left,right;} Node;

Node T[100000];

void depth(int D[],int id,int d){
    D[id] = d;
    if (T[id].right != NIL) depth(D,T[id].right,d);
    if (T[id].left != NIL) depth(D,T[id].left,d+1);
}

int decide_type(int id){
    if (T[id].left != NIL && T[id].parent != NIL) {
        return 1;
    }else if (T[id].parent != NIL){
        return 2;
    }else{
        return 0;
    }
}

void Child_id(int id){
    if (T[id].left == NIL) {
        cout << "[]" << endl;
    }else{
        id = T[id].left;
        cout << "[" << id;
        while (T[id].right != NIL) {
            cout << ", " << T[id].right;
            id = T[id].right;
        }
        cout << "]" << endl;
    }
}

int main(){
    int root=0;
    int D[100000];
    int N;
    cin >> N;
    for (int  i = 0; i < N; i++) {
        T[i].left = NIL;
        T[i].right = NIL;
        T[i].parent = NIL;
    }
    for (int i = 0; i < N; i++) {
        int id,count;
        cin >> id >> count;
        int child,beforchild = -1;
        
        for (int c = 0; c < count; c++) {
            cin >> child;
            T[child].parent = id;
            if (c == 0) T[id].left = child;
            if (beforchild != -1) T[beforchild].right = child;
            beforchild = child;
        }
    }
    while (T[root].parent != NIL) {
        root = T[root].parent;
    }
    depth(D,root,0);
    char type[3][32] = {"root, ",
        "internal node, ",
        "leaf, "};
    
    
    for(int i = 0; i < N; i++){
        printf("node %d: parent = %d, depth = %d, %s",i,T[i].parent,D[i],type[decide_type(i)]);
        Child_id(i);
    }
    
    return 0;
}