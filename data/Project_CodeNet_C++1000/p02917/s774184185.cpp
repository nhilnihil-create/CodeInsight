#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
/* main */
int main(){
    int n;
    cin >> n;
    vector<int> B(n - 1);
    for (int &b : B) cin >> b;

    int ans = B[0] + B.back();

    for (int i = 0; i < n - 2; i++) {
        ans += min(B[i], B[i + 1]);
    }
    cout << ans << '\n';
}