#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
bool isSquare(int n) {
	int d = (int)sqrt(n) - 1;
	while (d * d < n) ++d;
	return d * d == n;
}

int main(){
int N, D; cin >> N >> D;
 vector<vector<int>> X(N, vector<int>(D));
 for (int i = 0; i < N; ++i) {
 for (int j = 0; j < D; ++j) {
 cin >> X[i][j];
 }
 }
 int ans = 0;
 for (int i = 0; i < N; ++i) {
 for (int j = i+1; j < N; ++j) {
 int norm = 0;
 for (int k = 0; k < D; ++k) {
 int diff = abs(X[i][k] - X[j][k]);
 norm += diff * diff;
 }
 // check whether norm = k for some k
 bool flag = false;
 for (int k = 0; k <= norm; ++k) {
 if (k * k == norm) {
 flag = true;
 }
 }
 if (flag) ++ans;
 }
 }
 cout << ans << endl;
    return 0;
}