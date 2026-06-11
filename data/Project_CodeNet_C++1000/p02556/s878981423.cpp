#include <iostream>
using namespace std;

void chmax(long long &a, long long b) {
    if (a < b) a = b;
}
void chmin(long long &a, long long b) {
    if (a > b) a = b;
}

int main() {
    int n; cin >> n;
    long long p_max, p_min, m_max, m_min;
    p_max = m_max = -1e18 - 100;
    p_min = m_min = 1e18 + 100;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        chmax(p_max, x + y);
        chmin(p_min, x + y);
        chmax(m_max, x - y);
        chmin(m_min, x - y);
    }
    long long ans = max(p_max - p_min, m_max - m_min);
    cout << ans << endl;
}