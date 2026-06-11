#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
using ll = long long;
using P = pair<ll, ll>;
vector<int> to[100005];
int cost[100005];
double PI = acos(-1);
int x[10];
int y[10];

double dist(ll i, ll j) {
    int xx = (x[i]-x[j])*(x[i]-x[j]);
    int yy = (y[i]-y[j])*(y[i]-y[j]);
    return sqrt(xx+yy);
}

signed main(){
    double a, b, x;
    cin >> a >> b >> x;

    double s = x/a;
    double rad;
    double lim = b*a/2.0;
    if(lim>s) {
        double h = 2*s/b;
        rad = atan2(b, h);
    } else {
        double h = 2*(a*b-s)/a;
        rad = atan2(h,a);
    }

    double ans = rad/(2.0*PI)*360;

    cout << setprecision(10)<< ans << endl;

    return 0;
}

