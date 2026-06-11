#include <iostream>
using namespace std;
#define MAX 100001
#define NIL -1
struct Node{int parent,right,left;};
struct Node D[MAX];
int T[MAX];
void rec(int u,int p){
    T[u]=p;
    if(D[u].right!=NIL)rec(D[u].right,p);
    if(D[u].left!=NIL)rec(D[u].left,p+1);
}
void print(int u){
    int p;
    cout<<"node "<<u<<": parent = "<<D[u].parent<<", depth = "<<T[u]<<", ";
    if(D[u].parent==-1)cout<<"root, ";
    else if(D[u].parent!=-1&&D[u].left!=-1)cout<<"internal node, ";
    else if(D[u].left==-1)cout<<"leaf, ";
    if(D[u].left!=-1){
        p=D[u].left;
        cout<<"["<<p;
        while(true){
            if(D[p].right!=NIL){
                p=D[p].right;
                cout<<", "<<p;
            }
            else break;
        }
        cout<<"]"<<endl;
    }
    else if(D[u].left==-1)cout<<"[]"<<endl;
    
    
}
int main(void){
    int i,n,a,m,c,l,j;
    
    cin>>n;
    for(i=0;i<n;i++)D[i].parent=D[i].right=D[i].left=NIL;
    for(i=0;i<n;i++){
        cin>>a>>m;
        for(j=0;j<m;j++){
            cin>>c;
            if(j==0)D[a].left=c;
            else D[l].right=c;
            l=c;
            D[c].parent=a;
        }
    }
    for(i=0;i<n;i++){
        if(D[i].parent==NIL){
            break;
        }
    }
    rec(i,0);
    for(i=0;i<n;i++)print(i);
    return 0;
}