#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M,V,P;
    cin >> N >> M >> V >> P;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    int ans = P;
    int sum = A[P-1];
    for(int i = P; i < N; i++) {
        int cnt = max(0LL,V-(P-1)-(N-i-1)-1);
        cnt *= M;
        if(A[P-1] > A[i]+M) {
            break;
        }
        if(sum+cnt <= (A[i]+M)*(N-(P-1)-(N-i-1)-1)) {
            ans++;
        }
        sum += A[i];
    }
    cout << ans << endl;
}
