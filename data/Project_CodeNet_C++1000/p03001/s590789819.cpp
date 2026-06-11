#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    ll h,w,x,y;
    cin >> w >> h >> x >> y;
    cout << setprecision(10) << fixed;

    ld a1,a2;
    ld ans = (ld)(h*w)/2;
    cout << ans << " ";

    if(x*2 == w && y*2 ==h){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    
    return 0;
}