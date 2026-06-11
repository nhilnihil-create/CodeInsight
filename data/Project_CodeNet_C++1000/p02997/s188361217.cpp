#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;


int main(){
	
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    ll n,k; cin>>n>>k;
    if (k>(n-1)*(n-2)/2){
        cout<<-1<<endl;
        return 0;
    }

    cout << n-1+ (n-1)*(n-2)/2 - k<<endl;
    REP(i,n-1) cout<<1<<' '<<2+i<<endl;
    ll count=0;
    FOR(i,2,n-1){
        FOR(j,i+1,n){  
            if(count==((n-1)*(n-2)/2 - k)) return 0;
            cout<<i<<' '<<j<<endl;
            count++;
            // cout << count<<endl;
        }
    }
    return 0;
}