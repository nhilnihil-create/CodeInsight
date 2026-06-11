#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];
    int cnt = 0;
    int ans = 0;
    for(int i=N-1; i>0; --i){
        if(H[i]<=H[i-1]){
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 0;
    }
    cout << ans << endl;
    return 0;
}
