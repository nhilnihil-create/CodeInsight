#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define  pb     push_back
#define  all(x) (x).begin(), (x).end()
#define  rep(i,a,b) for(int i=a ; i<b ; ++i)
#define  repr(i,a,b) for(int i=a ; i>=b ; --i)
#define  deb(x) cout << #x << " - " << x << "\n";
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  D2(x)  { cerr << "[" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }
#define  ps(x,y) fixed<<setprecision(y)<<x
 
#define PI 3.141592653589793
const ll MOD = 1e9 + 7;
const ll INF = 1000000000000;
const ll MAX_N = 1e6 + 2;

void solve(){
    int a,b,c,k; cin >> a >> b >> c >> k;
    int cnt=0;
    while(a>=b) {
        b*=2;
        cnt++;
    }
    while(b>=c){
        c*=2;
        cnt++;
    }
    if(cnt<=k) cout << "Yes";
    else cout << "No";
}
 
int main() {
    IOS;
    // int t; cin >> t;
    int t = 1; 
    while(t--) solve();
}