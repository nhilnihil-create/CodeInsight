#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int charToInt(char c)
{
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main()
{
    int N, T;
    cin >> N >> T;
    vector<int> A(N+1), B(N+1);
    rep(i, N)
    {
        cin >> A.at(i+1) >> B.at(i+1);
    }

    //二つのDPを考える
    int DP1[N + 2][T + 1], DP2[N + 2][T + 1];
    rep(i, N + 2)
    {
        rep(j, T + 1)
        {
            DP1[i][j] = 0;
            DP2[i][j] = 0;
        }
    }

    //DP1[i][j]は1~i番目までの料理を使って、j分までに食べられる最大の点数
    for(int i=1;i<N+1;i++){
        //i番目の料理を食べる場合のスコア: DP[i][j] = DP[i-1][j-A[i]]+B[i]
        //i番目の料理を食べない場合のスコア: DP[i][j] = DP[i-1][j]
        for(int j=0;j<T+1;j++){
        if(j>=A[i]){
            DP1[i][j] = max(DP1[i-1][j], DP1[i-1][j-A[i]]+B[i]);
        }else{
            DP1[i][j] = DP1[i-1][j];
        }
      }
    }

    //DP2[i][j]はi~N番目までの料理を使って、j分までに食べられる最大の点数
    for(int i=N;i>0;i--){
        //i番目の料理を食べる場合のスコア: DP[i][j] = DP[i-1][j-A[i]]+B[i]
        //i番目の料理を食べない場合のスコア: DP[i][j] = DP[i-1][j]
        for(int j=0;j<T+1;j++){
        if(j>=A[i]){
            DP2[i][j] = max(DP2[i+1][j], DP2[i+1][j-A[i]]+B[i]);
        }else{
            DP2[i][j] = DP2[i+1][j];
        }
      }
    }
    for(int i=0;i<N+1;i++){
        for(int j=0;j<T;j++){
            //cout<<i<<" "<<j<<" "<<DP1[i][j]<<endl;
        }
    }

    int max_score = 0;
    for(int i=1;i<N+1;i++){
        //i番目のやつを最後に持ってくるときに、それ以外のやつでT-1分の間に食べられる料理のスコアの最大値を求めればよい
        for(int j=0;j<T;j++){
            //i-1までのやつをj分、i+1以降の奴をT-1-j分使って食べるときの最大値を求める
            if(max_score<DP1[i-1][j]+DP2[i+1][T-1-j]+B[i]){
                max_score = DP1[i-1][j]+DP2[i+1][T-1-j]+B[i];
            }
        }
    }

    cout << max_score << endl;

    return 0;
}