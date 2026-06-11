#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<pair<double, int>> order(n);
    for (int i = 0; i < n; i++){
        double p = atan2((double)y[i], (double)x[i]);
        order[i] = {p, i};
    }
    sort(order.begin(), order.end());
    double ans = 0;
    for (int i = 0; i < n; i++){
        long long tmp_x = 0;
        long long tmp_y = 0;
        for (int j = 0; j < n; j++){
            tmp_x += x[order[(i + j) % n].second];
            tmp_y += y[order[(i + j) % n].second];
            ans = max(ans, sqrt(tmp_x * tmp_x + tmp_y * tmp_y));
        }
        tmp_x = 0;
        tmp_y = 0;
        for (int j = 0; j < n; j++){
            tmp_x += x[order[(n + i - j) % n].second];
            tmp_y += y[order[(n + i - j) % n].second];
            ans = max(ans, sqrt(tmp_x * tmp_x + tmp_y * tmp_y));
        }
    }
    cout << setprecision(20) << ans << endl;
}