#include<iostream>
using namespace std;
struct Node{int parent,left,right;};
struct Node T[100001];
#define NIL -1
int D[100001],n,dim,child,v,l,s;
void getDepth(int u,int p){
    D[u]=p;
    if(T[u].right!=NIL) getDepth(T[u].right,p);
    if(T[u].left!=NIL) getDepth(T[u].left,p+1);
}
void printchild(struct Node T[],int p,int d){
    if(d==0){
        if(T[p].left!=NIL){
            cout<<T[p].left;
            printchild(T,T[p].left,d+1);
        }
    }
    else if(T[p].right!=NIL){
            cout<<", "<<T[p].right;
            printchild(T,T[p].right,d);
     }
    
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) T[i].parent=T[i].right=T[i].left=NIL;
    for(int i=0;i<n;i++){
        cin>>v>>dim;
        for(int j=0;j<dim;j++){
            cin>>child;
            if(j==0) T[v].left=child;
            else  T[l].right=child;
            l=child;
            T[child].parent=v;
        }
    }
    for(int i=0;i<n;i++){
        if(T[i].parent==NIL) s=i;
    }
    getDepth(s,0);
    for(int i=0;i<n;i++){
        cout<<"node "<<i<<": ";
        cout<<"parent = "<<T[i].parent<<", ";
        cout<<"depth = "<<D[i]<<", ";
        if(T[i].parent==NIL) cout<<"root, [";
        else if(T[i].left==NIL) cout<<"leaf, [";
        else cout<<"internal node, [";
        printchild(T,i,0);
        cout<<"]"<<endl;
    }
}
