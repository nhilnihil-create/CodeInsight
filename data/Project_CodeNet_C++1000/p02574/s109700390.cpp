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
typedef vector<bool> vb;
typedef vector<ll>	vl;
typedef vector<pii>	vpii;
typedef vector<pl>	vpl;
typedef vector<vi>	vvi;
typedef vector<vl>	vvl;
typedef vector<double> vd;


const int mod = 1000000007;
const int inf = 1000000000;
const int N = 2000007, M = N;
ll i,j,cnt,par;
vi vec[N];



void solve() {
  ll n;
  cin>>n;

  ll x, m = INT_MIN , g = 0 , p = 0;
  map<int,int>mp;

  bool f = 0;

  for(int j=0;j<n;j++) {
    cin>>x;

    for(int i=2;i*i<=x;i++) {
        if(x%i == 0) {
            mp[i]++;
            if(mp[i] > 1) f = 1;
            while(x%i == 0) x/=i;
        }
    }
    if(x > 1) mp[x]++;
    if(mp[x] > 1) f = 1;

  }

  if(!f) cout<<"pairwise coprime\n";
  else {
    for(auto p : mp) {
        if(p.ss == n) {
            cout<<"not coprime\n";
            return;
        }
    }
    cout<<"setwise coprime\n";
  }
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


