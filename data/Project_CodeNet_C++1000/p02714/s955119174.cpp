#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    string S; cin >> S;
    vector<vector<int>> vec(N, vector<int>(3, 0));
    for(int i = 0; i < N; ++i) {
        if(S[i] == 'R') vec[i][0]++;
        if(S[i] == 'G') vec[i][1]++;
        if(S[i] == 'B') vec[i][2]++;
        if(i == 0) continue;
        vec[i][0] += vec[i-1][0];
        vec[i][1] += vec[i-1][1];
        vec[i][2] += vec[i-1][2];
    }
    long long ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N-1; ++j) {
            if(S[i] == S[j]) continue;
            if(S[i] != 'R' && S[j] != 'R'){
                ans += vec[N-1][0] - vec[j][0];
                if(2*j - i < N && S[2*j - i] == 'R') ans--;
            }
            if(S[i] != 'G' && S[j] != 'G'){
                ans += vec[N-1][1] - vec[j][1];
                if(2*j - i < N && S[2*j - i] == 'G') ans--;
            }
            if(S[i] != 'B' && S[j] != 'B'){
                ans += vec[N-1][2] - vec[j][2];
                if(2*j - i < N && S[2*j - i] == 'B') ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}