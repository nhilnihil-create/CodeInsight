#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const double PI = 3.14159265358979;

int main() {
    double a, b, x; cin >> a >> b >> x;
    double theta;

    if(a * a * b / 2 < x){
        theta = atan(2 * (a * a * b - x) / (a * a * a));
    }else{
        theta = atan((a * b * b) / (2 * x));
    }

    theta = theta * 180 / PI;
    cout << setprecision(20) << theta << endl;
}
