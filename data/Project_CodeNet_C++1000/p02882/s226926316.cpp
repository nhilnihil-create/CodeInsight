// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    double a, b, x, s;
    cin >> a >> b >> x;
    s = x / a;
    if(s < a * b / 2.0){
        double th = atan(b * b / (2.0 * s));
        th *= 180 / M_PI;
        printf("%.7lf", th);
    } else {
        double th = atan(2.0 *(a * b - s)/ (a * a));
        th *= 180 / M_PI;
        printf("%.7lf", th);
    }
}