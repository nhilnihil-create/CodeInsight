#include<bits/stdc++.h>
using namespace std;

#define double long double
#define int long long
#define ALL(x) x.begin(),x.end()
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb(x) push_back(x)
#define eb emplace_back
#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend()) 
#define mp(x, y) make_pair(x, y)
#define INF 1000000000
#define MOD 998244353 
#define F(i, a, n) for(i=a;i<n;i++)
#define SI(x) cin>>x
#define DI(x, y) cin>>x>>y
#define TI(x, y, z) cin>>x>>y>>z
#define FI(w, x, y, z) cin>>w>>x>>y>>z
#define SO(x) cout<<x<<"\n"
#define DO(x, y) cout<<x<<" "<<y<<"\n"
#define TO(x, y, z) cout<<x<<" "<<y<<" "<<z<< "\n"
#define FO(w, x, y, z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int32_t main(void)
{
    FASTER;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    string s;
    SI(s);
    vi inversionRight;
    vi inversionLeft;
    int n = s.length();
    F(i, 0, n - 1)
    {
    	if(s[i] == 'R' && s[i + 1] == 'L')
    	{
    		inversionRight.pb(i);
    		inversionLeft.pb(i + 1);
    	}
    }
    int dp[n];
    memset(dp, 0, sizeof(dp));
    F(i, 0, n)
    {
    	if(s[i] == 'R')
    	{
    		int x = *lower_bound(ALL(inversionRight), i);
    		if((x - i) % 2)
    			dp[x + 1]++;
    		else
    			dp[x]++;	
    	}
    	if(s[i] == 'L')
    	{
    		int x = lower_bound(ALL(inversionLeft), i) - inversionLeft.begin();
    		if(inversionLeft[x] != i)
    			x--;
    		x = inversionLeft[x];
    		if((i - x) % 2)
    			dp[x - 1]++;
    		else
    			dp[x]++;
    	}
    }
    
    F(i, 0, n)
    	cout << dp[i] << " ";
    cout << "\n";
    
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}