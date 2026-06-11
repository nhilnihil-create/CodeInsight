#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N, M;
    cin>>N>>M;
    vector<pint> A(M);
    REP(i, 0, M){
        int a, b, d = 0;
        cin>> a >> b;
        REP(j, 0, b){
            int c;
            cin >> c;
            d += pow(2, c-1);
        }
        A[i] = {a, d};
    }
    int state = pow(2, N);
    vvi DP(M + 1, vi(state, 0));
    REP(i, 1, M+1){
        int a = A[i-1].first, b = A[i-1].second;
        DP[i][b] = a;
    }
    REP(i, 2, M+1){
        int a = A[i-1].first, b = A[i-1].second;
        REP(j, 0, state){
            if(j != 0 && DP[i-1][j] == 0) continue;
            int o = j | b;
            if(DP[i][o] == 0 || DP[i][o] > DP[i-1][j] + a) DP[i][o] = DP[i-1][j] + a;
            if(DP[i][j] == 0 || DP[i][j] > DP[i-1][j]) DP[i][j] = DP[i-1][j];
        }
    }
    /*
    REP(i, 0, M + 1){
        REP(j, 0, state){
            cout << setw(5) << DP[i][j] << " ";
        }
        cout << endl;
    }*/
    int ans = __INT_MAX__;
    if(DP[M][state-1] == 0){
        cout << -1 << endl;
        return 0;
    }
    REP(i, 0, M+1){
        if(DP[i][state-1] != 0){
            ans = min(ans, DP[i][state-1]);
        }
    }
    cout << ans << endl;
}