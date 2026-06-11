#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    // < < < < < <
    // > > > > > >
    vector<int>A(S.size()+1);
    vector<int>B(S.size()+1);
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '<') {
            A[i+1] = A[i]+1;
        }
        if(S[S.size()-i-1] == '>') {
            B[S.size()-i-1] = B[S.size()-i]+1;
        }
    }
    int ans = 0;
    for(int i = 0; i <= S.size(); i++) {
        ans+=max(A[i],B[i]);
    }
    cout << ans << endl;
}