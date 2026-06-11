#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double m_ang = m / 60 * 360;
    double h_ang = h / 12 * 360 + m / 60 * 30;
    double m_x = b * cos(m_ang * M_PI / 180);
    double m_y = b * sin(m_ang * M_PI / 180);
    double h_x = a * cos(h_ang * M_PI / 180);
    double h_y = a * sin(h_ang * M_PI / 180);
    double dist = sqrt((m_x - h_x) * (m_x - h_x) + (m_y - h_y) * (m_y - h_y));
    printf("%.10lf\n", dist);
    return 0;
}
