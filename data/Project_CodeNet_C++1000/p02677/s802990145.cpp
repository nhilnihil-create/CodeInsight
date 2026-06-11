#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
#include <iomanip>
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;
double pi = 3.14159265358979;

int main(){

    int a, b, h, m;
    cin >> a >> b >> h >> m;
    
    double theta = (5.5 * m - 30.0 * h) * pi / 180;
    
    double c = a * a + b * b - 2 * a * b * cos(theta);

    double min = abs(a - b);
    double max = a + b;
    double mid;
    
    rep(i,200){
        mid = (min + max) / 2;
        if(mid * mid > c){
            max = mid;
        } else {
            min = mid;
        }
    }
    
    cout << setprecision(15) << max << "\n";
        
    return 0;
}
