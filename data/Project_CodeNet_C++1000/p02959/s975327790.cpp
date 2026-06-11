#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 100000;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N+1);
    for(int i = 0; i <= N; i++) {
        cin >> A[i];
    }
    vector<int>B(N);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        if(A[i]) {
            if(A[i] < B[i]) {
                B[i]-=A[i];
                ans+=A[i];
            }
            else {
                ans+=B[i];
                B[i] = 0;
            }
        }
        if(B[i]) {
            if(A[i+1] < B[i]) {
                ans+=A[i+1];
                A[i+1] = 0;
            }
            else {
                ans+=B[i];
                A[i+1]-=B[i];
            }
        }
    }
    cout  << ans << endl;
}
