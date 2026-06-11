#include <bits/stdc++.h>
using namespace std;

long long int n, a, b;

void solve(){
    long long tot = a + b;
    if (tot <= 0){
        cout << "0\n";
        return;
    }
    long long ans = (n / tot) * a + min(n % tot, a);
    cout << ans << "\n";
    return;
}


int main(){
   	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> a >> b){
        solve();
	}
	return 0;
}