#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(void){
    double W,H,x,y;
    cin >> W >> H >> x >> y;
    
    double S = H * W / 2;
    int ans = 0;
    if(x*2 == W && y*2 == H){
        ans++;
    }
    
    cout << fixed << setprecision(10) << S << " " << ans << endl;
}
