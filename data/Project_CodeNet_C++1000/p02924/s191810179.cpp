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


const int mod = 100000007;
const int inf = 100000005;
const int N = 200007, M = N;
int i,j,idx,cnt,par;

void solve() {
    ll n;
    cin>>n;

    ll ans = 1;

    if(n == 1) {
        cout<<"0\n";
        return;
    }

    fo(i,3,n+1) {
        ans+=(i-1);
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


