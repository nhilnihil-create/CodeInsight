
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

void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    ll cnt = 0;
    fo(i,0,n-1) {
        if(s[i] == s[i+1]) cnt++;
    }
    int f = 0;
    char c = (s[0] == 'L') ? 'R' : 'L';
    
    for(int i=0;i<n;) {
      if(!k) break;

      int ii = i;
      while(s[ii] == c && ii<n) ii++;
      if(ii != i) {
        if(ii!=n) {
            cnt+=2;
            k--;
        }
        else {
           cnt = n - 1;
           break;
        }
        i = ii;
      }
      else i++;
    }
    cout<<cnt<<"\n";
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


