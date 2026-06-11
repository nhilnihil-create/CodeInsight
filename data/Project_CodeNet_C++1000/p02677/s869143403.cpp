#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define PI 3.14159265358979323846264338327950L
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int a,b,h,m;cin >> a >> b >>h >>m;
    double ang1,ang2,theta;
    theta =  PI * 2 * (h / 12.0 + m / 60.0/ 12.0 - m / 60.0);
    double ans=0;
    ans = sqrt(a*a+b*b-2*a*b*cosl(theta));
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}


