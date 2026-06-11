#include <bits/stdc++.h>
using namespace std;
using usize = ::std::size_t;
using u64 = ::std::int_least64_t;
//using u64 = long long;
static constexpr u64 Inf = ::std::numeric_limits<u64>::max() / 2;
int main(int argc, char *argv[])
{
    
    
    cin.tie(0) ;
    ios::sync_with_stdio(false) ;
    
    int a,b,x;
    cin >> a >> b >> x;
    double base = (double) pow(a, 2)*b/2;
    double denominator;
    double numerator;
    if(x > base) {
        denominator = (double) a;
        numerator = ((double) pow(a, 2)*b - x) * 2/ pow(a, 2);
    //cout << denominator << " " << numerator << " " << denominator/numerator << endl;
        cout << fixed << setprecision(10) << atan(numerator/denominator)*180.0/acos(-1) << endl;
    } else {
        denominator = (double) x * 2/(a * b);
        numerator = (double) b;
        cout << fixed << setprecision(10) << atan(numerator/denominator)*180.0/acos(-1) << endl;
    //cout << denominator << " " << numerator << " " << denominator/numerator << endl;
    }
    return 0;
    
}
