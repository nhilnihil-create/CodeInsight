#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    vector<int> count(N, 0);
    //Rの個数についての探索
    rep(i, N){
        if(S[i] == 'R'){
            int R_cnt = 0;
            while(S[i+1] != 'L'){
                R_cnt++;
                i++;
            }
            count[i] += (R_cnt/2);
            count[i+1] += (R_cnt + 2 - 1)/2;
            count[i]++;
            count[i+1]++;
        }
    }
    //Lの個数についての探索
    for(int i = N-1; i >= 0; i--){
        if(S[i] == 'L'){
            int L_cnt = 0;
            while(S[i-1] != 'R'){
                L_cnt++;
                i--;
            }
            count[i] += (L_cnt/2);
            count[i-1] += (L_cnt + 2 - 1)/2;
        }
    }
    rep(i, N) cout << count[i] << endl;
    return 0;
}