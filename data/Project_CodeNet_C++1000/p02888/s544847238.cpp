#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
#define N 2005
int n, l[N];
ll ans;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
        cin >> l[i];
    }
	sort(l + 1, l + n + 1);
	for(int i = 1; i <= n - 2; i++){
		for(int j = i + 1; j <= n - 1; j++){
			ans += (lower_bound(l + j + 1, l + n + 1, l[i] + l[j]) - l) - j - 1;
        }
    }
	cout << ans << endl;
	return 0;
}