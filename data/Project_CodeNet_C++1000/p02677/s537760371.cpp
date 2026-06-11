#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
static const double pi = 3.141592653589793;

int main(){
    double ans, theta;
    int a,b,h,m; cin >> a >> b >> h >> m;
    theta = (double)(h/12.0)+(double)(m/(60.0*12.0)) - (double)(m/60.0);
    // cout << theta << endl;
    ans = (double)(a*a + b*b) - (double)(2*a*b*cosl(2*pi*theta));
    ans = sqrt(ans);
    printf("%.10f\n",ans);
}