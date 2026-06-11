#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct P{
    double x, y, angle;
    P(double x, double y) : x(x), y(y){
        if(abs(x) + abs(y) < 0.001)angle = 0;
        else{
            angle = acos(x / sqrt(x*x + y*y));
            if(y < 0){
                angle = 2*acos(-1) - angle;
            }
        }
    }

    bool operator<(const P &p)const{
        return angle < p.angle;
    }
};

int main(void){
    int n;
    long long ans = 0;
    vector<P> p;
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        p.push_back(P(x, y));
    }
    sort(p.begin(), p.end());

    for(int i=0;i<n;i++){
        long long x = 0, y = 0;
        for(int j=0;j<n;j++){
            x += p[(i+j)%n].x;
            y += p[(i+j)%n].y;
            ans = max(ans, x*x + y*y);
        }
    }
    cout << fixed << setprecision(16) << (double) sqrt((double)ans) << endl;
}
