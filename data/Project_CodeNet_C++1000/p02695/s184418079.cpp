#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tmp, res = 0;
int N,M,Q;
vector<int> A;
vector<vector<int>> F;
void solve(vector<int> &A, int cur, int x){
    A[cur] = x;
    if (cur==N-1){
        tmp = 0;
        for (int i=0; i<Q; ++i){
            if (A[F[i][1]] - A[F[i][0]]==F[i][2]) tmp += F[i][3];
        }
        res = max(res, tmp);
    }else {
        for (int next_v=x; next_v<=M; ++next_v) solve(A,cur+1,next_v);
    }
}
int main() {
    cin >> N >> M >> Q;
    A.resize(N);
    F.resize(Q, vector<int>(4));
    for (int i=0; i<Q; ++i){
        for (int j=0; j<4; ++j){
            cin >> F[i][j];
            if (j==0 || j==1) F[i][j]--;
        }
    }
    for (int x=1; x<=M; ++x) solve(A,0,x);
    cout << res << endl;
    return 0;
}