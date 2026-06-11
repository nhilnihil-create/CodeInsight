#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector <vector <int>> c(m+1);

    int a,b;
    rep(i,n){
        cin >> a >> b;
        if(a<=m){
            c[a].push_back(b);
        }
    }

    priority_queue <int> q;
    ll su;
    su=0;
    int u;
    int l;
    rep(i,m){
        l=c[i+1].size();
        rep(j,l){
            q.push(c[i+1][j]);
        }
        if(q.size()==0){
            continue;
        }
        u=q.top();
        q.pop();
        su+=u;
    }

    cout << su << endl;

    return 0;
}