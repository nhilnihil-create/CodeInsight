#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;

int main(){FIN

    ll n;cin>>n;
    string s;cin>>s;
    
    ll mx = 0; 
    FOR(i,1,n-1){
        ll i1 = 0, i2 = i;

        ll cnt=0;
        while(i2<n){
            if(s[i1] == s[i2]) cnt++;
            else { 
                mx = max(mx,cnt);
                mx = min(mx,ll(i));
                cnt = 0;
            }
            i1++; i2++;
        }
        mx = max(mx,cnt);
        mx = min(mx,ll(i));
    }
    cout<<mx<<endl;
    return 0;
}