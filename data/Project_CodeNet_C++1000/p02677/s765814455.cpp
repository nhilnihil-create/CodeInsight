#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI=3.14159265358979323846;
int main(void){
    double hour_hand,minute_hand,H,M;
    cin >> hour_hand >> minute_hand >> H >> M;
    
    double min = M + H * 60;
    double theta = 11.0/360.0 * min;
    while(theta > 2.0){
        theta -= 2.0;
    }
    double ans;
    ans = pow(hour_hand,2.0) + pow(minute_hand,2.0) - 2*hour_hand*minute_hand*cos(theta*PI);
    ans = pow(ans,0.5);
    
    cout << setprecision(30) << ans << endl;
}