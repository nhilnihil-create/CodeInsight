
#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,n) for(i=a;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sortrev(x) sort(all(x),greater<int>())
#define pi 3.1415926535897932384626

typedef pair<int,int> pii;
typedef pair<ll, ll> pl;
typedef vector<int>	vi;
typedef vector<ll>	vl;
typedef vector<pii>	vpii;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef vector<double> vd;


const int mod = 100000007;
const int inf = 100000005;
const int N = 200005, M = N;
ll i,j,idx;
int dp[50][50];

void solve() {
  ll n;
  cin>>n;

  vl vec(n);
  fo(i,0,n) cin>>vec[i];

  sortall(vec);
  ll ans = 0 , k;

  fo(i,0,n-2) {
    fo(j,i+1,n) {
        idx = lower_bound(all(vec) , vec[i]+vec[j]) - vec.begin();
        k = idx - j - 1;
        ans+=k;
    }
  }
  cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}


