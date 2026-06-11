#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int N,M,Q;
vector<int> a,b,c,d;
vector<int> A;
ll ans=0;
void DFS(vector<int>&V){
    if(V.size()==N+1){
        ll tmp=0;
        rep(i,Q){
            if(V[b[i]]-V[a[i]]==c[i]){
                tmp+=d[i];
            }
        }
        ans = max(ans,tmp);
        return;
    }else{
        int tail = V.back();
        for(int nv=tail;nv<=M;nv++){
            V.push_back(nv);
            DFS(V);
            V.pop_back();
        }
    }
}

int main(){
    cin >> N >> M >> Q;
    a.assign(Q,0);
    b.assign(Q,0);
    c.assign(Q,0);
    d.assign(Q,0);
    rep(i,Q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    vector<int> V(1,1);
    DFS(V);
    cout << ans << endl;
    return 0;
}