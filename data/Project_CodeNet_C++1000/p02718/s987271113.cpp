#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum+=A[i];
    }
    sort(A.rbegin(),A.rend());
    for(int i = 0; i < M; i++) {
        if(A[i]*4*M < sum) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
