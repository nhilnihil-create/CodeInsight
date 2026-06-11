#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll n,k;
bool solve(ll mid, vector<ll> a, vector<ll> f){
    ll now = 0;
    for(int i=0;i < n;i++){
        now += max(a[i] - mid/f[i],0ll);
    }
    if(now > k) return 0;
    else return 1;
}
int main(){
    cout << fixed << setprecision(10);
    cin >> n >> k;
    vector<ll> a(n), f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a.begin(),a.end());
    sort(f.rbegin(),f.rend());
    ll left = -1, right = 1e18+10;
    while(left + 1 < right){
        ll mid = (left + right)>>1;
        if(solve(mid,a,f)){
            right = mid;
        }else left = mid;
    }
    cout << right << endl;
    return 0;
}