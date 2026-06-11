#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define pb push_back
#define ALL(v) v.begin(),v.end()
const long long INF = 1LL << 60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
using CP = std::complex<double>;
int main()
{
    double a, b;
    cin >> a >> b;
    double h, m;
    cin >> h >> m;
    h *= 5;
    h += m/12.0;
    double t = abs(h-m)*6;
    //cout << t << endl;
    const double pi = acos(-1.0);
    double rad= t*pi/180;
    double c = cos(rad);
    //if(c < 0) c *= -1.0;
    //cout << c << endl;

    double alpha = (h * 60 + m) / 720 * (pi * 2);
    double beta = m / 60 * (pi * 2);
    double theta = alpha - beta;
    //cout << theta << endl;

    double l = a*a+b*b-2.0*a*b*cos(rad);
    l = sqrt(l);
    cout << fixed << setprecision(10) << l << endl;
    //cout << l << endl;


    return 0;
}