#include <iostream>
using namespace std;

struct node {
    node():p(-1),b(-1),c(-1),d(-1){}
    int p;
    int b;
    int c;
    int d;
};

void setdepth(node t[], int id, int d) {
    t[id].d=d;
    if(t[id].c!=-1) setdepth(t, t[id].c, d+1);
    if(t[id].b!=-1) setdepth(t, t[id].b, d);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    node t[100000];
    cin>>n;
    for(int i=0; i<n; i++) {
        int id, k, ci, cp=-1;
        cin>>id>>k;
        for(int j=0; j<k; j++) {
            cin>>ci;
            t[ci].p=id;
            if(j) t[cp].b=ci;
            else t[id].c=ci;
            cp=ci;
        }
    }
    int root;
    for(root=0; root<n&&t[root].p!=-1; root++);
    setdepth(t, root, 0);
    for(int i=0; i<n; i++) {
        cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = "<<t[i].d;
        if(t[i].p==-1) cout<<", root, [";
        else if(t[i].c==-1) cout<<", leaf, [";
        else cout<<", internal node, [";
        if(t[i].c!=-1) {
            cout<<t[i].c;
            for(int j=t[t[i].c].b; j!=-1; j=t[j].b) cout<<", "<<j;
        }
        cout<<"]\n";
    }
    return 0;
}