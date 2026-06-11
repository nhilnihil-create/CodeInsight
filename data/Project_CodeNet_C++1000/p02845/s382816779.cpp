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

const ll MOD = INF + 7;



int main(){
    int n;
    cin >> n;
    VEC(int, a, n);

    queue<int>que;
    que.push(0);
    que.push(0);
    que.push(0);
    ll res = 1;

    rep(i, n){
        int cnt = 0;
        bool f = true;
        rep(j, 3){
            int now = que.front();
            que.pop();
            if(now == a[i]){
                if(f){
                    f = false;
                    now++;
                }
                cnt++;
            }
            que.push(now);
        }
        res *= cnt;
        res %= MOD;
    }
    cout << res << endl;
}