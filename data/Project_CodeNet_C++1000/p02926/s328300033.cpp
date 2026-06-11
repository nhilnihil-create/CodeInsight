#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}


signed main(void) {
    int n;
    cin >> n;
    vi x(n),y(n);
    rep(i,n)cin >> x[i] >> y[i];
    vector<pair<double,int> > v(n);
    rep(i,n)v[i] = make_pair(atan2(y[i],x[i]),i);
    sort(all(v));
    double ans = 0;
    //rep(i,n)cout << " " << v[i].second << endl;
    rep(s,n){
        int xx = 0, yy = 0;
        int l = v[s].second;
        rep(i,n){
            int r = v[(s+i)%n].second;
            xx += x[r], yy += y[r];
            ans = max(ans, sqrt(xx*xx + yy*yy));
        }
    }
    cout << shosu(15) << ans << endl;
}
