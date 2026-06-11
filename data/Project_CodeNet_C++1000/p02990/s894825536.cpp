#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
ll v[3000][3000] , mod = 1e9 + 7;
int main() {
    int n , k;
    cin >> n >> k;
	v[0][0] = 1;
	for(int i = 1; i <= n; i++){
		v[i][0] = 1;
		for(int j = 1; j <= i; j++){
			v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % mod;
        }
	}
	for(int i = 1; i <= k; i++){
		cout << v[n - k + 1][i] * v[k - 1][i - 1] % mod << endl;
    }
	return 0;
}