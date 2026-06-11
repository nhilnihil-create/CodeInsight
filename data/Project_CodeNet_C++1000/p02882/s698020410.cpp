#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
typedef long long ll;
typedef long double ld;


int main(){
    ld a, b, x;
    cin >> a >> b >> x ;
    
    ld ans = 0;

    if(x <= a * a * b / 2){
        ans = 90 - atan(2 * x/ (b * b *a)) * 180 /PI;
    }
    else{
        ans = atan((2 * b - 2 * x / (a * a)) / a) * 180 /PI ; 
    }
    cout << setprecision(16) << ans << endl;
}

/**
 * 断面が直角三角形(x <= a * a * b / 2)を満たす
 * 
 * x = b * b * tan(90 - ans) * a / 2 
 * 
 * 90 - ans = atan(2 * x/ (b * b *a))
 * 
 * ans = 90 - atan(2 * x/ (b * b *a))
 * 
 * 
 * 断面が台形(x > a * a * b / 2)
 * 
 * 
 * x = ((b  - a * tan(ans)) + b) * a * a / 2 
 * 
 * 
 * 
 * 2 * b - a * tan(ans) = 2 * x / (a * a)
 * 
 * (2 * b - 2 * x / (a * a)) = a * tan(ans)
 * 
 * ans = atan((2 * b - 2 * x / (a * a)) / a)
 * 
 * 
 * 
 **/