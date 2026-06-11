#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n,m;
    cin >> n >> m;
    vector<P> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(),ab.end());
    ll ans = 0;
    int id = 0;
    priority_queue<ll> pq;
    for(int i=1;i<=m;i++){
        while(ab[id].first<=i&&id<n){
            pq.push(ab[id].second);
            ++id;
            if(id>=n) break;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}