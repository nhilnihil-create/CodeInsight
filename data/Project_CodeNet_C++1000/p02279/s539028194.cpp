#include <bits/stdc++.h>
using namespace std;
#define NIL -1

struct Node{
    int p,l,r;
};

void setDepth(vector<Node> &T,vector<int> &D,int u,int p){
    D[u]=p;
    if(T[u].r!=NIL){
        setDepth(T,D,T[u].r,p);
    }
    if(T[u].l!=NIL){
        setDepth(T,D,T[u].l,p+1);
    }
}

void printChildren(vector<Node> &T,int u){
    int c=T[u].l;
    if(c!=NIL){
        cout<<c;
        c=T[c].r;
        while(c!=NIL){
            cout<<", "<<c;
            c=T[c].r;     
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<Node> T(100001);
    vector<int> D(100001);
    for(int i=0;i<n;i++){
        T[i].p=T[i].l=T[i].r=NIL;
    }
    for(int i=0;i<n;i++){
        int x,y,w;
        cin>>x>>y;
        for(int j=0;j<y;j++){
            int z;
            cin>>z;
            if(j==0){
                T[x].l=z;
            }
            else{
                T[w].r=z;
            }
            w=z;
            T[z].p=x;
        }
    }
    for(int i=0;i<n;i++){
        if(T[i].p==-1){
            setDepth(T,D,i,0);
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<"node "<<i<<": parent = "<<T[i].p<<", depth = "
            <<D[i]<<", ";
        if(T[i].p==-1){
            cout<<"root";
        }
        else if(T[i].l==-1){
            cout<<"leaf";
        }
        else{
            cout<<"internal node";
        }   
        cout<<", [";
        printChildren(T,i);
        cout<<']'<<endl;
    }
}
