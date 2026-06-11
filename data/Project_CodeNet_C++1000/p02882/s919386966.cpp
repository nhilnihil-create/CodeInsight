#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    double a,b,x; cin >> a >> b >> x;
    double th = 2*x/(a*a);
    double ans;
    if(th>b) ans = atan2(2*b-th,a);
    else {
        double tei = 2*x/(a*b);
        ans = atan2(b,tei);
    }
    double pai = 3.14159265;
    cout << setprecision(10) << ans*180.0/pai << endl;
}

