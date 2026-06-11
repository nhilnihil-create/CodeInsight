#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MAX 25
#define NIL -1

struct Node{
    int p,l,r;
};

int n;
Node tree[MAX];

void init(){
    for(int i=0;i<MAX;i++){
        tree[i].p = tree[i].r = tree[i].l = NIL;
    }
}

void print_pre(int r){
    if(r==NIL) return;
    else {
        cout << " " << r;
        print_pre(tree[r].l);
        print_pre(tree[r].r);
    }
}

void print_in(int r){
    if(r==NIL)return;
    else {
        print_in(tree[r].l);
        cout << " " << r;
        print_in(tree[r].r);
    }
}

void print_post(int r){
    if(r==NIL)return;
    else{
        print_post(tree[r].l);
        print_post(tree[r].r);
        cout << " " << r;
    }
}

void print(){
    int root;
    for(int i=0;i<n;i++)if(tree[i].p==NIL)root=i;
    cout << "Preorder\n";
    print_pre(root);
    cout << "\n";
    cout << "Inorder\n";
    print_in(root);
    cout << "\n";
    cout << "Postorder\n";
    print_post(root);
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> n;
    int id,lft,rgt;

    for(int i=0;i<n;i++){
        cin >> id >> lft >> rgt;
        tree[id].l=lft;
        tree[id].r=rgt;
        tree[lft].p = tree[rgt].p = id;
    }

    print();
}

