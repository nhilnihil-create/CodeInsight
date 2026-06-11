#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, D, A;
    cin >> N >> D >> A;

    int X[N], H[N];
    P p[N];
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        p[i] = P(a, b);
    }

    sort(p, p+N);
    for(int i=0; i<N; i++){
        X[i] = p[i].first;
        H[i] = p[i].second;
    }

    ll ans = 0;
    int sum[N+1];
    fill(sum ,sum+N+1, 0);
    for(int i=1; i<=N; i++){
        sum[i] += sum[i-1];

        if(H[i-1] <= sum[i]) continue;

        int rest = H[i-1] - sum[i];
        int cnt;
        if(rest%A == 0) cnt = rest / A;
        else cnt = rest/A + 1;

        ans = ans + cnt;
        sum[i] += A*cnt;

        int right = lower_bound(X, X+N, X[i-1]+2*D+1) - X;
        sum[right+1] -= A*cnt;
    }

    cout << ans << endl;

    return 0;
}
