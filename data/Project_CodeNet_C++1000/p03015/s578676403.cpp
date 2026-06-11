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
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

ll MOD = INF + 7;
ll dp[100100][2];

int main(){
    string s;
    cin >> s;
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++){
        for(int f = 0; f < 2; f++){
        for(int j = 0; j < 2; j++){     //aのiビット
            for(int k = 0; k < 2; k++){ //bのiビット
                if(j == 1 && k == 1)continue;
                if(f == 0 && j + k > s[i] - '0')continue;
                dp[i + 1][f || (j + k < s[i] - '0')] += dp[i][f] % MOD;
                dp[i + 1][0] %= MOD;
                dp[i + 1][1] %= MOD;
            }
        }
        }
    }
  	
    //rep(i, s.size() + 1){rep(j, 2)cout << dp[i][j] << " ";cout << endl;}
    ll res = dp[s.size()][0] + dp[s.size()][1] % MOD;
  res %= MOD;
    cout << res << endl;
}
