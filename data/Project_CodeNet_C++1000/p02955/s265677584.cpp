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

const string YES = "Yes";
const string NO = "No";
const ll mod = 1e9+7;


int main(){
	// cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(false);

    ll n,k; cin>>n>>k;
    vll a(n); vll b(n);
    REP(i,n) cin>>a[i];
    ll a_sum = accumulate(ALL(a), 0LL); 

    vll cd;

    for(ll i=1;i*i<=a_sum;i++){
        if(i*i==a_sum) {
            cd.push_back(i);
            break;
        }
        if (a_sum%i==0) {
            cd.push_back(i); cd.push_back(a_sum/i);
        }
    }
    VSORTR(cd);
    ll mx;
    // cout << cd.top() << endl;
    for(ll p: cd){
        // cout<< p << endl;
        REP(i,n) b[i] = a[i] % p;
        VSORT(b);
        ll b_sum = accumulate(ALL(b), 0LL);
        ll nn = n - b_sum / p;
        ll am = accumulate(b.begin(), b.begin()+nn,0LL);
        
        if (am <= k) {
            cout << p <<endl;
            return 0;
        }
    }
    // cout << 121234 <<endl;
    return 0;
    
}

