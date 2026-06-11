#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    int ans = 0;
    vector<int> d(N);
    rep(i, N){
        cin >> d[i];
    }
    for(int i=0; i<N-1; ++i){
        for(int j=i+1; j<N; ++j) ans += d[i]*d[j];
    }
    cout << ans << endl;
    return 0;
}
