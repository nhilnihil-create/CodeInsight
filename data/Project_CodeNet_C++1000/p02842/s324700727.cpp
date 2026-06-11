#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    string ans = ":(";
    for (int x=0; x<=N; ++x) if ((int)(x*1.08)==N) ans = to_string(x);
    cout << ans << endl;
    return 0;
}