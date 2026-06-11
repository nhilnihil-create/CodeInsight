#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

const double PI = acos(-1.0);
int main() {
    int A,B,H,M; cin >> A >> B >> H >> M;
    double degree = 30*H + M*0.5 - 6*M;
    double ans = sqrt(pow(A, 2) + pow(B, 2) - 2*A*B*cos(degree*PI/180));
    cout << fixed << setprecision(10) << ans << endl;
}