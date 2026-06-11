#include <bits/stdc++.h>
typedef long long       ll;
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define forr(i,b,e)		  for(int i=(int)b;i<(int)e;++i)
#define deb(x)			  cerr << "# " << (#x) << " = " << (x) << endl;
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
const int INF = 1234567890;

int res[10010];

int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ll n;
    cin >> n;
    clr(res, 0);
    for (ll x = 1; x <= 100; x++) {
    	for (ll y = 1; y <= 100; y++) {
    		for (ll z = 1; z <= 100; z++) {
    			ll sum = x*x 
    			       + y*y 
    			       + z*z 
    			       + x*y 
    			       + x*z 
    			       + y*z;
    			if (sum > n) break;
    			res[sum]++;
    		}
    	}
    }
    fore(i, 1, n+1) {
    	cout << res[i] << '\n';
    }
    return 0;
}
// Dinosaurs are cool