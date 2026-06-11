
#include <iostream>

using namespace std;
#define NIL -1;

struct Node{int parent, left, right;};
Node T[600000];
int D[600000];

int getDepth(int u){
    int d=0;
    while(T[u].parent!=-1){
        u=T[u].parent;
        d++;
    }
    return d;
}

void setDepth(int u, int p){
    D[u]=p;
    if(T[u].right!=-1)setDepth(T[u].right,p);
    if(T[u].left!=-1)setDepth(T[u].left,p+1);
}

void print(int u){
    int i,c;
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<T[u].parent<<", ";
    cout<<"depth = "<<D[u]<<", ";

    if(T[u].parent==-1)cout<<"root, ";
    else if(T[u].left==-1)cout<<"leaf, ";
    else cout<<"internal node, ";

    cout<<"[";

    for(i=0,c=T[u].left;c!=-1;i++,c=T[c].right){
        if (i) cout<<", ";
        cout<<c;
    }
    cout<<"]"<<endl;

}

int main()
{
    int n,i,v,d,c,l,r;
    cin>>n;
    for(i=0;i<n;i++)T[i].parent=T[i].left=T[i].right=-1;
    for(i=0;i<n;i++){
        cin>>v>>d;
        for(int j=0;j<d;j++){
            cin>>c;
            if (j==0)T[v].left=c;
            else T[l].right=c;
            l=c;
            T[c].parent=v;
        }
    }

    for(i=0;i<n;i++){
        if(T[i].parent==-1) r=i;
    }
    setDepth(r,0);

    for(i=0;i<n;i++)print(i);

    return 0;
}
