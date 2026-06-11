
//左子右兄弟表达法
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1e5+5;
const int NIL=-1;

struct node{
    int p,l,r;
};

node t[maxn];
int n,d[maxn];

void print(int u)
{
    int i,c;
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<t[u].p<<", ";
    cout<<"depth = "<<d[u]<<", ";
    if(t[u].p==NIL){
        cout<<"root, ";
    }else if(t[u].l==NIL){
        cout<<"leaf, ";
    }else{
        cout<<"internal node, ";
    }
    cout<<"[";
    for(int i=0,c=t[u].l;c!=NIL;i++,c=t[c].r){
        if(i){
            cout<<", ";
        }
        cout<<c;
    }
    cout<<"]"<<endl;
}

int rec(int u,int p)
{
    d[u]=p;
    if(t[u].r!=NIL){
        rec(t[u].r,p);
    }
    if(t[u].l!=NIL){
        rec(t[u].l,p+1);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        t[i].p=t[i].l=t[i].r=NIL;
    }
    int v,d,c,l,r;
    for(int i=0;i<n;i++){
        cin>>v>>d;
        for(int j=0;j<d;j++){
            cin>>c;
            if(j==0){
                t[v].l=c;
            }else{
                t[l].r=c;
            }
            l=c;
            t[c].p=v;
        }
    }
    for(int i=0;i<n;i++){
        if(t[i].p==NIL){
            r=i;
        }
    }
    rec(r,0);
    for(int i=0;i<n;i++){
        print(i);
    }
    return 0;
}
/*
13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0
*/

