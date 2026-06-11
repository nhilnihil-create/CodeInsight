#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007
 
int N,M,Q;
vector<int> a,b,c,d;
ll ans = 0;
 
void DFS(vector<int> &V){
    if(V.size()==N+1){
        ll tmp = 0;
        rep(i,Q){
            if(V[b[i]]-V[a[i]]==c[i]){
                tmp += d[i];
            }
        }
        ans = max(ans,tmp);
        return;
    }else{
        int tail = V.back();
        for(int i=tail;i<=M;i++){
            V.push_back(i);
            DFS(V);
            V.pop_back();
        }
    }
}
int main(){
    cin >> N >> M >> Q;
    rep(i,Q){
        int a_,b_,c_,d_;
        cin >> a_ >> b_ >> c_ >> d_;
        a.push_back(a_);
        b.push_back(b_);
        c.push_back(c_);
        d.push_back(d_);
    }
    vector<int> V(1,1);
    DFS(V);
    cout << ans << endl;
    return 0;
}