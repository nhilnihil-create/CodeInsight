#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <stack>
#include <memory>
using namespace std;
const int MAX=100005;
const int NIL=-1;

struct node{
    int p,l,r;
    int depth;
};
node t[MAX];
int n;

void print(int u)
{
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<t[u].p<<", ";
    cout<<"depth = "<<t[u].depth<<", ";
    if (t[u].p==NIL) {
        cout<<"root, ";
    }
    else if(t[u].l==NIL) cout<<"leaf, ";
    else cout<<"internal node, ";
    cout<<"[";
    for (int i=0,c=t[u].l; c!=NIL; i++,c=t[c].r) {
        if (i) {
            cout<<", ";
        }
        cout<<c;
    }
    cout<<"]"<<endl;
}

void rec(int u,int p)
{
    t[u].depth=p;
    if (t[u].r!=NIL) {
        rec(t[u].r, p);
    }
    if (t[u].l!=NIL) {
        rec(t[u].l, p+1);
    }
}
int main()
{
    //freopen("/Users/mac/Desktop/C++?¨????/test/test.txt", "r", stdin);
    int d,v,c,l = 0,root = 0;
    cin>>n;
    for (int i=0; i<n; i++) {
        t[i].p=t[i].l=t[i].r=t[i].depth=NIL;
    }
    for (int i=0;i<n; i++) {
        cin>>v>>d;
        for (int j=0; j<d; j++) {
            cin>>c;
            if (j==0) {
                t[v].l=c;
            }
            else{
                t[l].r=c;
            }
            l=c;
            t[c].p=v;
        }
    }
    for (int i=0; i<n; i++) {
        if (t[i].p==NIL) {
            root=i;
        }
    }
    rec(root, 0);
    for (int i=0; i<n; i++) {
        print(i);
    }
    return 0;
}