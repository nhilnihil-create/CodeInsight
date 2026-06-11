#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n; ll k; cin >> n >> k;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int cnt1 = 0, cnt2 = 0;
    rep(i, n){
        for(int j = i+1; j < n; j++){
            if(v[i] > v[j])cnt1++;
        }
    }
    rep(i, n){
        rep(j, n){
            if(v[i] > v[j])cnt2++;
        }
    }
    ll ans = cnt1*k;
    ans %= MOD;
    ans += cnt2*((k*(k-1)/2)%MOD);
    ans %= MOD;
    cout<<ans<<endl;
    system("pause");
}
