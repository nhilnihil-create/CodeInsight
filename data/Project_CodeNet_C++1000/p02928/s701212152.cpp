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

const int MOD = 1e9 + 7;

inline int mul(int a, int b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}

inline int add(int a, int b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}

inline int f(int x)
{
	int ans = x*(x-1)/2;
	ans %= MOD;
	return ans;
}


int32_t main(void)
{
    FASTER;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    int n, k;
    DI(n, k);
    int inversions = 0;
    int a[n];
    
    F(i, 0, n)
    	SI(a[i]);
    
    int right = 0;
    F(i, 0, n)
    {
    	F(j, i + 1, n)
    	{
    		if(a[i] > a[j])
    			++inversions;
    	}
    	F(j, 0, n)
    		if(a[i] > a[j])
    			++right;
    }
    
    int ans = mul(inversions, k);
    ans = add(ans, mul(f(k), right));
    
    SO(ans);
    
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}