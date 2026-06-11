#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
	int N , L , R;
	int ans = 2020;
    cin >> L >> R;
	N = R - L;
	for(int i = L; i < L + min(2019 , N); i++){
		for(int j = i + 1; j <= min(R , i + 2019); j++){
			ans = min(((i % 2019) * (j % 2019)) % 2019 , ans);
		}
	}
    cout << ans << endl;
}