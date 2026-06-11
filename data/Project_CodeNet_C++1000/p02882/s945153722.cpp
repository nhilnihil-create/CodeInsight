#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    double a,b,x;
    cin >> a >> b >> x;
    double s = x/a;
    double h = 2*(a*b - s)/a;
    double w = 2*x/(a*b);
    if(a*b/2 < s) cout << atan2(h,a)/acos(-1) * 360.0/2  << endl;
    else cout << atan2(b,2*x/(a*b))/acos(-1) * 360.0/2 << endl;
    return 0;
}