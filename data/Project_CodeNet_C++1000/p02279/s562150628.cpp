#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1
struct Node{
int p;//存储父节点的序号
int l;//存储子节点的序号
int r;//存储兄弟节点的序号
};
Node T[MAX];
int n,D[MAX];
void print(int u){
cout<<"node "<<u<<": ";
cout<<"parent = "<<T[u].p<<",";
cout<<" depth = "<<D[u]<<", ";
if (T[u].p==NIL) cout<<"root, ";
else if (T[u].l == NIL) cout<<"leaf, ";
else cout<<"internal node, ";
cout<<"[";
for (int i=0, c = T[u].l; c!=NIL;i++, c=T[c].r){
if (i) cout<<",";
if(i!=0) cout<<" ";
cout<<c;
}
cout<<"]"<<endl;
}
int rec(int u,int p){
    D[u]=p;
    if(T[u].r!=NIL) rec(T[u].r,p);
    if(T[u].l!=NIL) rec(T[u].l,p+1);
}

int main(){
    int i,j,d,v,c,l,r;
    cin>>n;
    for(i=0;i<n;i++) {
    T[i].p =T[i].l=T[i].r=NIL;
    }
    for(i=0;i<n;i++){
    cin>>v>>d;
    for(j=0;j<d;j++){
    cin>>c;
    if(j==0) T[v].l=c;//输入子节点第一个
    else T[l].r=c;//输入子节点其他位
    l=c;
    T[c].p=v;//传递到子节点
    }
    }
    for(i=0;i<n;i++){
    if(T[i].p==NIL) r=i;//找到根节点，方便递归
    }
    rec(r,0);
    for(i=0;i<n;i++) print(i);
    return 0;
}

