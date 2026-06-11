#include <stdio.h>
#include <iostream>
using namespace std;
// node最大量
#define MAX 100000
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
};

// 配列で保持する
Node gNode[MAX];

// 先行順巡回
void preParse(int u){
    if(u == NIL)return;
    printf(" %d",u);
    preParse(gNode[u].left);
    preParse(gNode[u].right);
}

// 中間順巡回
void inParse(int u){
    if(u == NIL)return;
    inParse(gNode[u].left);
    printf(" %d",u);
    inParse(gNode[u].right);
}

// 後行順巡回
void postParse(int u){
    if(u == NIL) return;
    postParse(gNode[u].left);
    postParse(gNode[u].right);
    printf(" %d",u);
}

int main(){
    int left,right,v,n,root = 0;
    cin >> n;
    // 初期化
    for(int i = 0;i < n;++i){
        gNode[i].parent = gNode[i].left = gNode[i].right = NIL;
    }
    
    for(int i = 0;i < n;++i){
        cin >> v >> left >> right;
        gNode[v].left = left;
        gNode[v].right = right;
        // 親の設定
        if(left != NIL){
            gNode[left].parent = v;
        }
        if(right != NIL){
            gNode[right].parent = v;
        }
    }

    // rootを探す
    for(int i = 0;i < n;++i){
        if(gNode[i].parent == NIL){
            root = i;
        }
    }
    
    cout << "Preorder\n";
    preParse(root);
    cout << "\n";
    cout << "Inorder\n";
    inParse(root);
    cout << "\n";
    cout << "Postorder\n";
    postParse(root);
    cout << "\n";
    
    return 0;
}
