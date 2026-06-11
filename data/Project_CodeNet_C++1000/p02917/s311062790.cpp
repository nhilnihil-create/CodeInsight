#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> b(n - 1);
    int ans = 0;
    for(int i = 0; i + 1 < n; i++) cin >> b[i];
    ans = b[0] + b[n - 2];
    for(int i = 1; i + 1 < n; i++) ans += min(b[i], b[i - 1]);
    cout << ans;

    return 0;
}

