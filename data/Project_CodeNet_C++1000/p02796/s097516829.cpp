#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using pint = pair<int, int>;
using pll = pair<ll,ll>;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> arms(n);
    ll x,l;
    REP(i,n){
        cin >> x >> l;
        arms[i]={x-l,x+l};
    }
    sort(arms.begin(),arms.end(),[](pll a,pll b){return a.second < b.second;});
    int count = 0;
    ll now = -LINF;
    for(int i=0;i<n;i++){
        if(now<=arms[i].first){
            now = arms[i].second;
            count++;
        }
    }
    COUT(count);
    return 0;
}  