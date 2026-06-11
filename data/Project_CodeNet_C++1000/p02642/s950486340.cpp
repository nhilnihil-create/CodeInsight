#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    const long long INF = 0;


    long long N;
    cin >> N;

    vector<int> A(N);

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    sort(A.begin(),A.end());

    long long Amax = A.back();

    // DP テーブル
    bool dp[Amax+1];

    // DP テーブル全体を初期化
    for (int i = 0; i < Amax + 1; ++i){
        dp[i] = false;
    }
    
    //数列に存在する項をすべてカウント

    for(int i = 0; i < N; ++i){
            dp[A.at(i)] = true;
    }

    //条件を満たさないものを除外

    for(int i = 0; i < N; ++i){
        if(dp[A.at(i)] == true){
            int j = 2;
            while(A.at(i) * j <= Amax + 1){
                dp[A.at(i) * j] = false;
                j++;
            }
        }
    }


    //同じ整数を除外

    for(int i = 0; i < N-1; ++i){
        if(A.at(i) == A.at(i+1)){
            dp[A.at(i)] = false;
        }
    }

    int ans = 0;

    for(int i = 0; i < Amax + 1; ++i){
        if(dp[i])ans++;
    }

    cout << ans << endl;

}
