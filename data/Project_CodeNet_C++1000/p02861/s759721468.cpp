#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const int mod = 1e9+7;

#define pi pair<int,int>
#define pl pair<lld,lld>

#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())
#define vuniq(x) x.erase(unique(x.begin(), x.end()), x.end())

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

int main() {
    ll N;
    cin >> N;
    vector<long double> X,Y;
    for (int i = 0; i < N; i++) {
        long double x,y;
        cin >> x >> y;
        X.pb(x); Y.pb(y);
    }
    vector<ll> v(N);
    iota(v.begin(), v.end(), 0);
    ll cnt = 0;
    long double ans = 0.0;
    do {
        for (int i = 1; i < v.size(); i++) {
            ans += sqrt((X[v[i-1]] - X[v[i]])*(X[v[i-1]] - X[v[i]]) + 
                   (Y[v[i-1]] - Y[v[i]])*(Y[v[i-1]] - Y[v[i]]));
        }
        cnt++;
    } while(next_permutation(v.begin(),v.end()));
    printf("%.10Lf\n",ans / (long double)cnt);
}