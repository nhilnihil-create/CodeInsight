#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<double>> XY(N);
    for(int i=0; i<N; i++){
        double x, y;
        cin >> x >> y;
        XY[i] = {atan2(x, y), x, y};
    }
    sort(XY.begin(), XY.end());
    double ans = 0;
    for(int i=0; i<N; i++) for(int n=0; n<=N; n++){
        double x = 0, y = 0;
        for(int j=i; j<i+n; j++){
            x += XY[j%N][1];
            y += XY[j%N][2];
        }
        ans = max(ans, sqrt(x*x + y*y));
    }
    cout << fixed << setprecision(10) << ans << endl;
}
