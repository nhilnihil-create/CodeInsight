#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, a, ans;
    cin >> N;
    map<long long, long long> mp;
    ans = 0;
    for (long long i = 1; i <= N; i++) {
        cin >> a;
        ans += mp[i - a];
        mp[i + a] ++;
    }
    cout << ans << endl;
 
    
}

