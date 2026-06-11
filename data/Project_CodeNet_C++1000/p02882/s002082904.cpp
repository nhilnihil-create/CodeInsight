#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const double pi = 3.14159265358979;
signed main(){
    double a,b,x;
    cin >> a >> b >> x;
    x/=a;
    if(x > a*b/2) {
        cout << fixed << setprecision(10) << atan2((a*b-x)*2,a*a)*180/pi << endl;
    }
    else {
        cout << fixed << setprecision(10) << atan2(b*b,x*2)*180/pi << endl;
    }
}