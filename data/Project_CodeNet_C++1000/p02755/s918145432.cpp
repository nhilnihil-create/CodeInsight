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
    int i,j,n,m;

    ll cnt , idx;
    vi temp;


    void solve() {
       ll x,y;
       cin>>x>>y;

       ll aa,bb;
       bool f = 0;
       fo(i,0,2001) {
         double a = i * 0.08;
         double b = i * 0.10;

         aa = (int)(a);
         bb = (int)(b);
         if(aa == x && bb == y) {
            f = 1;
            cout<<i<<"\n";
            break;
         }
       }
       if(!f) cout<<"-1\n";

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


