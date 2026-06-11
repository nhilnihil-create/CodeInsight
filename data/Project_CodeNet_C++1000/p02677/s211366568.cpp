#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

double A, B, H, M;

int main() {
    cout << fixed << setprecision(10);

    cin >> A >> B >> H >> M;

    double min = M*6;
    double min_rad = M_PI * min / 180;

    double hour = H*30 + M*30/60;
    double hour_rad = M_PI * hour / 180;

    double diff = abs(min_rad - hour_rad);

    double theta = (diff < M_PI) ? diff : 2*M_PI - diff;

    cout << sqrt(A*A + B*B - 2*A*B*cos(theta)) << endl;

    return 0;
}
