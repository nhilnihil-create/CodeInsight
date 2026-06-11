#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

struct node{
    int parent = -1;
    int left = -1;
    int right = -1;
};

vector<node> tree(100000);

int calcDepth(int id){
    int depth = 0;
    while(tree.at(id).parent != -1){
        id = tree.at(id).parent;
        depth++;
    }
    return depth;
}

int depth = 0;
void DFS(int id, vector<int> &node_depth){
    if(tree.at(id).left != -1){
        depth++;
        DFS(tree.at(id).left, node_depth);
        depth--;
    }
    if(tree.at(id).right != -1){
        DFS(tree.at(id).right, node_depth);
    }
    node_depth.at(id) = depth;
    return;

}

void printChild(int id){
    int child_left = tree.at(id).left;
    if(child_left == -1){
        cout << "[]";
        return;
    }
    cout << "[";
    while(tree.at(child_left).right != -1){
        cout << child_left << ", ";
        child_left = tree.at(child_left).right;
    }
    cout << child_left << "]";
}

void printMode(int id){
    if(tree.at(id).parent == -1){
        cout << "root";
    }else if(tree.at(id).left == -1){
        cout << "leaf";
    }else{
        cout << "internal node";
    }
}

int main(){
    int n; cin >> n;
    // vector<node> tree(n);
    vector<int> node_depth(n, -1);

    rep(i, n){
        int id, n_child; cin >> id >> n_child;
        int left_sib_id = -1;
        
        rep(j, n_child){
            int child_id; cin >> child_id;
            if(j == 0){
                tree.at(id).left = child_id;
            }
            if(left_sib_id != -1){
                tree.at(left_sib_id).right = child_id;
            }
            tree.at(child_id).parent = id;
            left_sib_id = child_id;
        }
    }
    int root_index;
    rep(i, n){
        if(tree.at(i).parent == -1){
            root_index = i;
            break;
        }
    }

    DFS(root_index, node_depth);
    rep(i, n){
        cout << "node " << i << ": parent = " << tree.at(i).parent << ", depth = " << node_depth.at(i) << ", ";
        printMode(i);
        cout << ", ";
        printChild(i);
        cout << endl;
    }

    return 0;
}
