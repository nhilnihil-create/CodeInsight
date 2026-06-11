#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main() {
	string n; cin >> n;
    int ans = 0;
    rep(i, n.size()) ans += n[i] - '0';
    if(ans%9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
   return 0;
}
