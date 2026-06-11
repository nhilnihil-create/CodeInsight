#include <stdio.h>
#include <iostream>
using namespace std;
// node最大量
#define MAX 100005
#define NIL -1

struct Node {
    int parent;
    int leaf;
    int root;
};

// 配列で保持する
Node gNode[MAX];
int n,gDepth[MAX];

void print(int node){
    cout << "node " << node << ": ";
    cout << "parent = " << gNode[node].parent << ", ";
    cout << "depth = " << gDepth[node] << ", ";
    
    if(gNode[node].parent == NIL) cout << "root, ";
    else if(gNode[node].leaf == NIL)cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    
    for(int i = 0,leaf = gNode[node].leaf;leaf != NIL;++i,leaf = gNode[leaf].root){
        if(i) cout << ", ";
        cout << leaf;
    }
    cout << "]" << endl;
}

// 再帰的に深さを求める
void rec(int node ,int parent){
    gDepth[node] = parent;
    if(gNode[node].root != NIL){
        // 右の兄弟に同じ深さを設定
        rec(gNode[node].root,parent);
    }
    if(gNode[node].leaf != NIL){
        // 最も左の子に自分の深さ+1を設定
        rec(gNode[node].leaf,parent + 1);
    }
}

int main(){
    int nodeNum,nodeIndex,node,l,root;
    cin >> n;
    // 初期化
    for(int i = 0;i < n;++i){
        gNode[i].parent = gNode[i].leaf = gNode[i].root = NIL;
    }
    
    for(int i = 0;i < n;++i){
        cin >> nodeIndex >> nodeNum;
        for(int j = 0;j < nodeNum;++j){
            cin >> node;
            if(j == 0){
                gNode[nodeIndex].leaf = node;
            }
            else{
                gNode[l].root = node;
            }
            l = node;
            gNode[node].parent = nodeIndex;
        }
    }
    
    // rootを探す
    for(int i = 0;i < n;++i){
        if(gNode[i].parent == NIL){
            root = i;
        }
    }
    
    rec(root,0);
    
    for(int i = 0;i < n;++i){
        print(i);
    }
    return 0;
}
