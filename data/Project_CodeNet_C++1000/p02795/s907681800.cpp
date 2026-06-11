#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int h, w, n;
    cin >> h >> w >> n;
    cout << ceil((n*1.0) / max(h, w));
    return 0;
}