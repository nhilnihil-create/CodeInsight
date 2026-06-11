typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
bool comp(const complex<double> &left,const complex<double> &right){
    return arg(left) < arg(right);
}
int main() {
    ll n;
    std::cin >> n;
    vector<complex<double>> xy(n);
    for (int i = 0; i < n; i++) {
        double tx,ty;
        std::cin >> tx>>ty;
        complex<double> tc(tx,ty);
        xy[i] = tc;
    }
    double res = 0;
    sort(xy.begin(),xy.end(),comp);
    for (int i = 0; i < n; i++) {
        pair<double,double> now={xy[i].real(),xy[i].imag()};
        res = max(res, sqrt(now.first*now.first+now.second*now.second));
        for (int j = 1; j < n; j++) {
            now.first  += xy[(i+j)%n].real();
            now.second += xy[(i+j)%n].imag();
            res = max(res, sqrt(now.first*now.first+now.second*now.second));
        }
    }
    
    std::cout <<setprecision(20)<< res << std::endl;
}
