#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define pb push_back
#define mpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define INF 1000000001
#define inf1 1000000000000000001
#define MOD 1000000007
#define pie 3.14159265358979323846264338327950L
#define N 100005
#define M 1e6+9
#define mid(l, r) l + (r - l) / 2
#define vec vector<int>
#define vecl vector<ll>
#define umap unordered_map<ll,ll>
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define endl "\n"
#define int long long
using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
ll gcd(ll a,ll b){ if(!a)return b;return gcd(b%a,a);}
ll lcm(ll a, ll b) { return (a*b)/ gcd(a,b);}

// ll n,k,a,b,c,d,x,y,z,m,l;
// ll ans;
// vecl arr(N);
// ll dp[509][509];
// ll pre[N];



void test_case() {
	
    int  h,n;
    cin>>h>>n;

    vec d(n), b(n);

    rep(i,n) {
        cin>>d[i]>>b[i];
    }

    int dp[N];

    for(int i=0; i<N; i++) {
        dp[i] = LONG_MAX;
    }


    

    dp[0] = 0;

    int ans = INT64_MAX;

    for(int i=1; i<=10*h; i++) {
        
        for(int j=0; j<n; j++) {
            if(i- d[j] >=0 && dp[i - d[j]] != LONG_MAX) {
                dp[i] = min(dp[i], dp[i-d[j]] + b[j]);
                if(i>=h) {
                    ans=min(ans, dp[i]);
                }
            }
        }
    }

    // for(int i=1; i<=h; i++) {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    cout<<ans<<endl;




}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(20);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int t = 1;
    // cin >> t;
    while(t--)
    {   
        test_case();
    }
}