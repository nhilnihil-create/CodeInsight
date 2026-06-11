#include <iostream>

using namespace std;
#define MAX 100001
#define NIL -1
struct Node{
    int p,l,r;
};
struct Node T[MAX];
int D[MAX];
void rec(int u,int p){
    D[u] = p;
    if(T[u].r!=NIL) rec(T[u].r,p);
    if(T[u].l!=NIL) rec(T[u].l,p+1);
}
void print(int u){
    cout<<"node "<<u<<": parent = "<<T[u].p<<", depth = "<<D[u]<<", ";

    if(T[u].p == NIL){
        cout<<"root, ";
    }
    else if(T[u].l==NIL){
        cout<<"leaf, ";
    }
    else{
        cout<<"internal node, ";
    }
    cout<<"[";
    for(int i=0,c=T[u].l;c!=NIL;i++,c=T[c].r){
            if(i) cout<<", ";
            cout<<c;
    }
    cout<<"]"<<endl;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        T[i].p=T[i].l=T[i].r=NIL;
    }
    int id,k;
    for(int i=0;i<n;i++){
        cin>>id>>k;
        for(int j=0;j<k;j++){
            int c;
            int l;
            cin>>c;
            if(j==0){
                T[id].l = c;
            }else{
                T[l].r = c;
            }
            l=c;
            T[c].p = id;
        }
    }
    int r;
    for(int i=0;i<n;i++){
        if(T[i].p==NIL) r=i;
    }
    rec(r,0);
    for(int i=0;i<n;i++){
        print(i);
    }

    return 0;
}

