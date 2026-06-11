#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    vector<int>B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.begin(),B.end());
    for(int i = 0; i < N; i++) {
        if(A[i] == B[N-1]) {
            cout << B[N-2] << endl;
        }
        else {
            cout << B[N-1] << endl;
        }
    }
}