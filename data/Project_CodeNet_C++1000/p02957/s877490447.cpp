#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);

int main() {
int A, B;
cin >> A >> B;
if(A%2 == B%2) cout << (A+B)/2 << endl;
else cout << "IMPOSSIBLE" << endl;
}
