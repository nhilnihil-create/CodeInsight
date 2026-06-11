#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<P>ans;
    for(int i = 1; i < N-1; i++) {
        if(A[i] < 0) {
            ans.push_back({A[N-1],A[i]});
            A[N-1]-=A[i];
        }
        else {
            ans.push_back({A[0],A[i]});
            A[0]-=A[i];
        }
    }
    cout << A[N-1]-A[0] << endl;
    ans.push_back({A[N-1],A[0]});
    for(int i = 0; i < N-1; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
