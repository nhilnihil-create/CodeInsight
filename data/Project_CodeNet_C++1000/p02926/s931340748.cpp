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

bool comp(ii a, ii b)
{
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

double eps = 1e-11;


int32_t main(void)
{
    FASTER;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    int n;
    SI(n);
    vii points(n);
    F(i, 0, n)
        DI(points[i].first, points[i].second);
    double ans = 0;
    sort(points.begin(), points.end(), comp);
    F(i, 0, n)
    {
        F(j, 0, n)
        {
            int end = (j < i) ? j + n : j;
            pair<double, double> res = {0, 0};
            for(int k = i; k <= end; k++)
            {
                res.first += points[k%n].first;
                res.second += points[k%n].second;
            }
            if(hypot(res.first, res.second) + eps > ans)
                ans = hypot(res.first, res.second);
        }
    }
    cout << setprecision(13) << ans << "\n";
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}
