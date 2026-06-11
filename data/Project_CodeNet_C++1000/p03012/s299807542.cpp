#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;
const int INF = 1000000000;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int val = 0;
    rep(i, N){
        cin >> a[i];
        val += a[i];
    }
    vector<int> sum(N+1, 0);
    for(int i = 1; i < N+1; i++){
        sum[i] = sum[i-1] + a[i-1];
    }

    int ans = INF;
    for(int i = 1; i < N; i++){
        int l = sum[i];
        int r = val - sum[i];
        ans = min(ans, (int)fabs(l-r));
    }

    cout << ans << endl;
    return 0;
}