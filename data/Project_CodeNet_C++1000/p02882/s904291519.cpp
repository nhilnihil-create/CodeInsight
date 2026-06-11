#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    int a, b, x;
    cin >> a >> b >> x;
    double theta;
    if(a*a*b<= 2*x)
        theta = atan(2.0*(a*a*b-x) / (double)(a*a*a));
    else
        theta = acos(-1.0)/2.0-atan(2.0*x/(double)(b*b*a));
    cout << 180.0*theta/acos(-1.0);
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}
