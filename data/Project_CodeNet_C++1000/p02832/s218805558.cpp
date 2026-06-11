#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, cnt = 1;
    cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> x;
    	if(x == cnt) cnt++;
    }
    cout << (cnt == 1 ? -1 : n - cnt + 1) << "\n";
    return 0;
}
