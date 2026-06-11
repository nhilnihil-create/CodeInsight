#include <iostream>

using namespace std;
int n;

class Node {
public:
    int id;
    int p;
    int l;
    int r;
};

Node T[30];

void preOrder(int u) {
    if (u == -1) {
        return;
    }
    cout << " " << u;
    preOrder(T[u].l);
    preOrder(T[u].r);
}

void midOrder(int u){
    if(u==-1){
        return;
    }
    midOrder(T[u].l);
    cout << " " << u;
    midOrder(T[u].r);
}

void postOrder(int u){
    if(u==-1){
        return;
    }
    postOrder(T[u].l);
    postOrder(T[u].r);
    cout << " " << u;
}

int main() {
    cin >> n;
    int id, left, right;
    for(int i=0;i<n;i++){
        T[i].p=-1;
    }
    for (int i = 0; i < n; i++) {
        cin >> id >> left >> right;
        T[id].l = left;
        T[id].r = right;
        T[left].p = T[right].p = id;
    }
    int root;
    for(int i=0;i<n;i++){
        if(T[i].p==-1){
            root=i;
        }
    }
    cout<<"Preorder"<<endl;
    preOrder(root);
    cout<<endl<<"Inorder"<<endl;
    midOrder(root);
    cout<<endl<<"Postorder"<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}