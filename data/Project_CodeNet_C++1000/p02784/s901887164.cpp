#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll H, N;
    cin >> H >> N;
    ll A=0, A_temp;
    for (ll i=0; i<N; i++) {
        cin >> A_temp;
        A+=A_temp;
    }
    string ans;
    if (A>=H) {
        ans = "Yes";
    }
    else {
        ans = "No";
    }
    cout << ans << endl;
}