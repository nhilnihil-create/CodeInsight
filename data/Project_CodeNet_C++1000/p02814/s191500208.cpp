#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    M *= 2;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int lcm = a[0];
    for(int i = 1; i < N; i++) { 
        lcm = lcm * (a[i])/(__gcd(lcm, a[i]));
        if(lcm > M) {
            return cout << 0, 0;
        }
    }
    for(int i = 0; i < N; i++) {
        if(!((lcm/a[i])&1)) {
            return cout << 0, 0;
        }
    }
    cout << ((M/lcm) + 1)/2 << endl;
    return 0;
}

