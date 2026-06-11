#include<iostream>
using namespace std;
#define MAX 100000

struct Node{
    int parent,left,right;
};

Node T[MAX];
int D[MAX],s;

int get_depth(int u, int p){
    D[u]=p;
    if(T[u].right != -1){
        get_depth(T[u].right,p);
    }
    if(T[u].left != -1){
        get_depth(T[u].left,p+1);
    }
}

void array_init(Node A[],int n){
    for(int i=0;i<n;++i){
        A[i].parent = A[i].left = A[i].right = -1;
    }
}

void print(int u){
    cout<<"node "<<u<<": parent = "<<T[u].parent<<", depth = "<<D[u]<<", ";
    if(T[u].parent == -1) cout<<"root, ";
    else if(T[u].left==-1) cout<<"leaf, ";
    else cout<<"internal node, ";
    cout<<"[";
    for(int i=0,c=T[u].left;c!=-1;i++,c=T[c].right){
        if(i) cout<<", ";
        cout<<c;
    }
    cout<<"]"<<endl;
}

int main(){
    int num,deg,left,root,child;
    cin >> s;
    array_init(T,s);
    for(int i=0;i<s;i++){
        cin >> num >> deg;
        for(int j=0;j<deg;j++){
            cin >> child;
            if(j==0){
                T[num].left=child;
            }
            else{
                T[left].right=child;
            }
            left=child;
            T[child].parent=num;
        }
    }
    for(int i=0;i<s;i++){
        if(T[i].parent==-1) root=i;
    }
    get_depth(root,0);
    for(int i=0;i<s;i++){
        print(i);
    }
    return 0;
}