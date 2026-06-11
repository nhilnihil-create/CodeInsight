#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,n) for(i=a;i<n;i++)
#define ll long long
#define ld long double
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


const int mod = 100000007;
const int inf = 100005;
const int N = 3e5, M = N;
ll i,j,n,m,idx,cnt;
char d[31][31];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


void solve() {
    ll n,k,r,s,p;
    string t;
    cin>>n>>k>>r>>s>>p>>t;

    ll ans = 0;
    vi vec(n,0);
    fo(i,0,n) {
        if(t[i] == 'r') {
            if(i<k || t[i-k] != 'r' || (t[i-k] == 'r' && !vec[i-k])) {
                vec[i] = 1,ans+=p;
            }
        }
        else if(t[i] == 's') {
            if(i<k || t[i-k] != 's' || (t[i-k] == 's' && !vec[i-k])) {
                vec[i] = 1,ans+=r;
            }
        }
        else {
            if(i<k || t[i-k] != 'p' || (t[i-k] == 'p' && !vec[i-k])) {
                vec[i] = 1,ans+=s;
            }
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


