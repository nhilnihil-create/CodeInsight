#include <bits/stdc++.h>

using namespace std;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;

#define PI 3.14159265358979323846

double solve() {
    int A, B, H, M; cin >> A >> B >> H >> M;
    double angle = 30 * H - 5.5 * M;
    if (angle < 0.0) {
        angle += 360.0;
    }
    if (angle > 180.0) {
        angle = 360.0 - angle;
    }
    double res = sqrt(A*A + B*B - 2 * A * B * cos(angle * PI / 180.0));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cout << std::setprecision(10) << solve() << endl;
}
