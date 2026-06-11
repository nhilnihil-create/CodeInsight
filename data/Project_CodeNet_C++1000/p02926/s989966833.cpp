#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ele{double x, y;};
bool cmp(const ele &a, const ele &b){
    return atan2(a.x, a.y) < atan2(b.x, b.y);
}

int main() {
    int N;
    cin >> N;
    vector<ele> e;
    int k = 0;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            k++;
            continue;
        }
        e.push_back({x, y});
    }
    N -= k;
    if(N == 0){
        cout << 0 << "\n";
        return 0;
    }
    sort(e.begin(), e.end(), cmp);
    double ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < N; ++j) {
            double x=0, y=0;
            for (int k = 0; k < i; ++k) {
                int id = (k+j) % N;
                x += e[id].x;
                y += e[id].y;
            }
            double temp = sqrt(x*x + y*y);
            ans = max(ans, temp);
        }
    }
    cout << setprecision(30) << ans;
    return 0;
}