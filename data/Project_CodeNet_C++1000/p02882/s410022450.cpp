#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    double a,b,x;
    cin >> a >> b >> x;

    double r, ans;
    double half = a*a*b/2.0;

    if(x < half){
        double e = 2.0*x/(a*b);
        r = atan(b/e);
        ans = r*360.0/(2.0*PI);
    } else {
        double c = 2*(a*a*b-x)/(a*a);
        double tan = a/c;
        r = atan(tan);
        ans = (PI/2.0-r)*360.0/(2.0*PI);
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}