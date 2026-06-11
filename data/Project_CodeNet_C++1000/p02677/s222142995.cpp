#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

double A, B;
int H, M;

int main() {
    cin >> A >> B >> H >> M;
    double radA = (60*H + M) * (2*M_PI / 720);
    double radB = M * (2*M_PI / 60);
    double C = sqrt(A * A + B * B - 2 * A * B * cos(radA - radB));
    cout << fixed << setprecision(10) << C << endl;
}