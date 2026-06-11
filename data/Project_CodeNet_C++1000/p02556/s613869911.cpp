#include <iostream>
using namespace std;

struct cdn {
    int x, y;
};

int main() {
    int N, maxRotPls, minRotPls, maxRotMns, minRotMns, ans;
    cin >> N;
    cdn cdns[N];
    for (int i = 0; i < N; i++) {
        cin >> cdns[i].x >> cdns[i].y;
    }
    
    // 初期化
    maxRotPls = minRotPls = cdns[0].x + cdns[0].y;
    maxRotMns = minRotMns = cdns[0].x - cdns[0].y;
    for (int i = 0; i < N; i++) {
        maxRotPls = max(maxRotPls, cdns[i].x + cdns[i].y);
        minRotPls = min(minRotPls, cdns[i].x + cdns[i].y);
        maxRotMns = max(maxRotMns, cdns[i].x - cdns[i].y);
        minRotMns = min(minRotMns, cdns[i].x - cdns[i].y);
    }
    ans = max(maxRotPls - minRotPls, maxRotMns - minRotMns);
    cout << ans << endl;
    return 0;
}