#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>A(N),F(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> F[i];
    }
    sort(A.begin(),A.end());
    sort(F.rbegin(),F.rend());
    int l = -1,r = INF;
    while (l+1 < r) {
        int mid = (l+r)/2;
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(mid == 0) {
                cnt += max(0LL,A[i]-F[i]);
                continue;
            }
            cnt += max(0LL,A[i]-mid/F[i]);
        }
        if(cnt <= K) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << endl;
}
