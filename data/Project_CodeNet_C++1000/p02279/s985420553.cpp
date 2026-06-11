#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define NIL -1
#define MAX 100001

struct Node{
    int parent;
    int left;
    int right;
};

Node tree[MAX];
int n;
int depth[MAX];

void setdepth(int r,int i){
    depth[r]=i;
    if(tree[r].right != NIL)setdepth(tree[r].right,i);
    if(tree[r].left != NIL) setdepth(tree[r].left,i+1);
}

void print_ch(int r){
    int ch = tree[r].left;
    for(int i=0;ch!=NIL;i++){
        if(i)cout << ", ";
        cout << ch;
        ch = tree[ch].right;
    }
}

void print(){
    for(int i=0;i<n;i++){
        cout << "node " <<i;
        cout << ": parent = " << tree[i].parent;
        cout << ", depth = " << depth[i];
        if(tree[i].parent==NIL)cout << ", root";
        else if(tree[i].left ==NIL)cout << ", leaf";
        else cout << ", internal node";
        cout << ", [";
        print_ch(i);
        cout << "]\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int id,k,ch;
    int left;
    for(int i=0;i<n;i++)tree[i].parent=tree[i].left=tree[i].right=NIL;

    for(int i=0;i<n;i++){
        cin >> id >> k;
        for(int j=0;j<k;j++){
            cin >> ch;
            tree[ch].parent=id;
            if(!j)tree[id].left=ch;
            else tree[left].right=ch;
            left=ch;
        }
    }

    int r;
    for(int i=0;i<n;i++){
        if(tree[i].parent==NIL)r=i;
    }

    setdepth(r,0);
    print();

    return 0;

}

