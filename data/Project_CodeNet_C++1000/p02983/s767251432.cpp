#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define  pb     push_back
#define  all(x) (x).begin(), (x).end()
#define  rep(i,a,b) for(int i=a ; i<b ; ++i)
#define  deb(x) cout << #x << " - " << x << "\n";
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)  { cerr << "[" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }
#define  ps(x,y) fixed<<setprecision(y)<<x
 
#define PI 3.141592653589793
const ll MOD = 1e9 + 7;
const ll INF = 10000000000;
const ll MAX_N = 1e6 + 2;

void solve(){
    ll l,r; cin >> l >> r;
    if(l==0 || r - l >= 2019){
        cout << "0";
        return;
    } else{
        ll mn = 2019;
        for(ll i=l;i<r;++i){
            for(ll j=i+1;j<=r;++j){
                mn = min(mn,(((i%2019)*(j%2019))%2019));
            }
        }
        cout << mn ;
        return;
    }
}

int main() {
    IOS;
    int t = 1;
    while(t--) solve();
}