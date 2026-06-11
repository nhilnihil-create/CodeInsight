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
    int n, k;
    cin >> n >> k;
    queue<P> que;
    if(k > (n - 1) * (n - 2) / 2)cout << -1 << endl;
    else {
        REP(i, 2, n){
            que.emplace(1, i);
        }
        int cnt = (n - 1) * (n - 2) / 2 - k;
      
        int now = 2;
        for(int i = 2; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
              if(cnt == 0)break;
                que.emplace(i, j);
                cnt--;
                if(cnt == 0)break;
            }
            if(cnt == 0)break;
        }
        cout << que.size() << endl;
    while(!que.empty()){
        cout << que.front().first << " " << que.front().second << endl;
        que.pop();
    }
    }
    
}
