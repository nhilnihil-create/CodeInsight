#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ITR(v,c) for(auto v=begin(c);v!=end(c);v++)
#define FOR(v,a,n) for(int v=a;v<(int)(n);v++)
#define FORE(x,arr) for(auto &x:arr)
#define REP(v,n) FOR(v,0,n)
#define ALL(c) begin(c),end(c)
const int DX[4]={0,1,0,-1}, DY[4]={-1,0,1,0};
const int INF = 1e9;
template<class T,class U>ostream&operator<<(ostream &os,const pair<T,U> &p){
    os<<"("<<p.first<<","<<p.second<<")";return os;}
template<class T>ostream&operator<<(ostream &os,const vector<T> &v){
    ITR(i,v)os<<*i<<(i==end(v)-1?"":" ");return os;}
//-----------------------------------------------------------

struct node {
    int i;
    int from;           // ??\???????????°
    vector<node*> to;   // ??\?¶????????????????
};
vector<node*> topological_sort(vector<node> &g) {
    vector<node*> sorted;
    queue<node*> q;
    FORE(nd,g) if(nd.from==0) q.push(&nd);
    while(!q.empty()) {
        node* v=q.front(); q.pop();
        sorted.push_back(v);
        FORE(u,v->to) {
            (u->from)--;
            if((u->from)==0) {
                q.push(u);
            }
        }
    }
    return sorted;
}

int main(int argc, char const *argv[]) {
    int V,E;
    cin>>V>>E;
    vector<node> g(V);
    REP(i,V) g[i].i=i;

    REP(i,E) {
        int a,b;
        cin>>a>>b;
        g[a].to.push_back(&g[b]);
        g[b].from++;
    }

    vector<node*> ans = topological_sort(g);
    REP(i,V) {
        cout<<ans[i]->i<<endl;
    }
    return 0;
}