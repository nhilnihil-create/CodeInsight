#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define drep(i,cc,n) for(int i=cc;i>n;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL <<60;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll choose2(ll n){
    return n*(n-1)/2;
}

int main() {
    double a,b,x;
    cin>>a>>b>>x;
    double s = x / a;

    double rad;
    double ans;

    if(x >= a * a * b) cout<<0<<endl;
    else {
        if(a * b / 2 >= s){
            double a2 = (2.0 * s) / b;
            rad = atan(b/a2);
        }
        else{
            double bu = (2.0 * s) / a - b;
            double b2 = b - bu;
            //double s2 = s - (bu * a);
            rad = atan(b2/a);
        }

        ans = rad * 180.0 * M_1_PI;
        printf("%.11lf\n",ans);
    }

    return 0;
}