#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
#define LARGE 1000000007

int main() {
    int n;
    cin >> n;

    double a = (n / 2) + (n % 2);
    double p = a / n;
    cout << fixed << setprecision(15) << p << endl;

	return 0;
}