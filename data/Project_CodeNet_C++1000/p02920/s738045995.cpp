#include<bits/stdc++.h>
using namespace std;

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
#define MOD 1000000007
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

bool solve()
{  
    int i, j;
    int n;
    SI(n);
    multiset<int> ms;
    vi v(1<<n);
    F(i, 0, 1 << n)
        SI(v[i]);
    sort(v.begin(), v.end());
    vi x;
    x.pb(v[(1<<n) - 1]);
    F(i, 0, (1<<n) - 1)
        ms.insert(v[i]);
    F(j, 0, n)
    {
        vi w = x;
        for(int i: x)
        {
            auto it = ms.lower_bound(i);
            if(it == ms.begin())
                return false;
            --it;
            w.push_back(*it);
            ms.erase(it);
        }
        DESC(w);
        x = w;
    }
    return true;
}

int32_t main(void)
{
    FASTER;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    if(solve())
        SO("Yes");
    else
        SO("No");
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}
