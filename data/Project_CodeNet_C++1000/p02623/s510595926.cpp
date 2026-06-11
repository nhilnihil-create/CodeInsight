#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>
#define vvi vector<vi >
#define str string
#define vs vector<str>
#define vb vector<bool>
#define slli set<lli>
#define mii map<int, int>
#define mlli map<int, lli>
#define msi map<str, int>
#define mp make_pair
#define pii pair<int, int>
#define pll pair<lli, lli>
#define vpii vector<pii >
#define vpll vector<pll >
#define pb push_back
#define loop(i, s, l, j) for(int i = s; i < l; i += j)
#define rloop(i, s, l, j) for(int i = s; i >= l; i -= j)
#define rep(i, n) loop(i,0,n,1)
#define rrep(i, n) rloop(i,n-1,0,1) 
#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ft first
#define sd second   
#define mit mii::iterator
#define vit vi::iterator
#define all(a) a.begin(),a.end()
#define min3(a, b, c) min(a, min(b, c))
#define mod 1000000007
#define inf 1000000000
#define limit 200001
/**********************************************************************************************************************************************/
int dx4[4] = {0, -1, 0, 1};
int dy4[4] = {1, 0, -1, 0};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int Power(int base,int exp){int ans=1;  while(exp > 0){if(exp&1)ans=(1LL*ans*base)%mod; exp=exp>>1; base=(1LL*base*base)%mod;}  return ans;}
/**********************************************************************************************************************************************/ 

void input()
{
    int n,m,k;
    cin >> n >> m >> k;
    vlli a(n), b(m);
    rep(i,n)
    {
        cin >> a[i];
        if(i)
            a[i] += a[i-1];
    }
    rep(i,m)
    {
        cin >> b[i];
        if(i)
            b[i] += b[i-1];
    }

    int ans = 0;
    rep(i,n+1)
    {
        lli t = k - (i ? a[i-1] : 0);
        if(t < 0)
            continue;
        int j = (upper_bound(all(b), t) - b.begin());
        ans = max(ans, i + j);
    }
    cout << ans << '\n';


}
 
int main()
{
    

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    fastio();
    int q = 1;
    //cin >> q;
    while(q--)
        input();
}