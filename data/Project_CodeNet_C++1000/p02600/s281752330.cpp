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
    int n; cin >> n;
    if(n>=400 && n<=599) cout << "8";
    else if(n>=600 && n<=799) cout << "7";
    else if(n>=800 && n<=999) cout << "6";
    else if(n>=1000 && n<=1199) cout << "5";
    else if(n>=1200 && n<=1399) cout << "4";
    else if(n>=1400 && n<=1599) cout << "3";
    else if(n>=1600 && n<=1799) cout << "2";
    else cout << "1";
}
 
int main() {
    IOS;
    // int t; cin >> t;
    int t = 1; 
    while(t--) solve();
}