#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;

int n, k, R, S, P, dp[5][N], mx[N];
string x;

int main()
{

      cin >> n >> k >> R >>S >> P >> x;

      for (int i=0; i<x.size(); i++){
      int temp =  mx[i];

    if (i+1 >k)
    temp-=mx[i-k+1], dp[0][i]=max(dp[1][i-k],dp[2][i-k]), dp[1][i]=max(dp[0][i-k],dp[2][i-k]), dp[2][i]=max(dp[1][i-k],dp[0][i-k]);

      dp[1][i]+= temp, dp[2][i]+=temp, dp[0][i]+=temp;
        if (x[i]=='r') dp[2][i]+=P;
        if (x[i]=='s') dp[0][i]+=R;
        if (x[i]=='p') dp[1][i]+=S;
        mx[i+1]= max(dp[0][i], dp[1][i]), mx[i+1]=max(mx[i+1],dp[2][i]);
      }

      cout << mx[n];
    return 0;
}
