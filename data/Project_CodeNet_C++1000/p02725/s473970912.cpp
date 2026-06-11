#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int K,N;
    cin >> K >> N;
    vector<int>A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    int mx = 0;
    for(int i = 0; i < N; i++) {
        if(i) {
            sum+=A[i]-A[i-1];
            mx = max(mx,A[i]-A[i-1]);
        }
    }
    sum+=K-A[N-1]+A[0];
    mx = max(mx,K-A[N-1]+A[0]);
    cout << sum-mx << endl;
}
