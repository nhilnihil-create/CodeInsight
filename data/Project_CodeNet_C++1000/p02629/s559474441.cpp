#include <bits/stdc++.h>

using namespace std;

using LL = long long;

// 701  = zy


void solver() {
    
    LL N; cin >> N;

    string ans = "";

    while(N >= 1){
        char add = ((N - 1 + 26) % 26) + 'a';
        N = ((N-1LL)/26);
        ans += add;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {

    ios_base :: sync_with_stdio(0); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    
    while(t--)
        solver();

    return 0;
}