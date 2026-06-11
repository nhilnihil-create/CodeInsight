#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>
 
#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll ZER = 0;
 

ll dp[1000100][2];

int main(){
  string s;
  cin >> s;
  reverse(ALL(s));
  int n = s.size();
  dp[0][1] = 1;
  rep(i, n){
    int d = s[i] - '0';
    int a[2][2];
    a[0][0] = d;
    a[0][1] = 10 - d;
    a[1][0] = d + 1;
    a[1][1] = 9 - d;

    rep(j, 2){
      dp[i + 1][j] = min(dp[i][0] + a[0][j], dp[i][1] + a[1][j]);
    }
    /*
    rep(j, 2)rep(k, 2)cout << a[j][k] << " ";
    cout << endl;
    cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
    */
  }
  //cout << dp[n][0] << " " << dp[n][1] << endl;
  cout << min(dp[n][0], dp[n][1] + 1) << endl;
}
 