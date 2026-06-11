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
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = INF + 7;

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n & 1)ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    reverse(ALL(s));
    deque<int> que;
    for(int i = 0; i < n + 1; i++){
        if(i == n)break;
        bool f = true;
        for(int j = m; j > 0; j--){
            if(j + i >= s.size())continue;
            if(s[i + j] == '1')continue;
            else {
                f = false;
                que.push_back(j);
                i += j - 1;
                break;
            }
        }
        if(f){
            cout << -1 << endl;
            return 0;
        }
    }
    while(!que.empty()){
        cout << que.back() << " ";
        que.pop_back();
    }
}