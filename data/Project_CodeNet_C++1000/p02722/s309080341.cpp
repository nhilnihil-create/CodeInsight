#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v;
    for(int i = 2; i * i <= N; i++){
        if(N % i == 0){
            v.pb(i);
            if(N != i * i) {
                v.pb(N/i);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i * i <= N - 1; i++) {
        if(( N - 1) % i == 0) {
            if(i * i == N - 1) ans ++;
            else ans += 2;
        }
    }
    
    for(auto x: v){
        int K = N;
        while(K % x == 0) K/=x;
        if((K - 1) % x == 0) ans++;
    }
    cout << ans << endl;


    return 0;
}

