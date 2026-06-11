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
    vector<int>a(n);
    vector<int>plus_num, minus_num, zero_num;
    bool plus = false, minus = false;
    rep(i, n){
        cin >> a[i];
        if(a[i] < 0){
            minus = true;
            minus_num.push_back(a[i]);
        }
        if(a[i] > 0){
            plus = true;
            plus_num.push_back(a[i]);
        }
        if(a[i] == 0)zero_num.push_back(a[i]);
    }


    sort(ALL(a));
    sort(ALL(plus_num));
    sort(ALL(minus_num));




    if(!plus && !minus){
        cout << 0 << endl;
        rep(i, n - 1)cout << 0 << " " << 0 << endl;
    }





    else if(plus && !minus){
        vector<P> p;
        int now = a[0], sum = 0;
        REP(i, 1, n - 2){
            p.emplace_back(now, a[i]);
            sum += now - a[i];
            now = now - a[i];
        }
        p.emplace_back(a[n - 1], now);
        sum = a[n - 1] - now;

        cout << sum << endl;
        for(auto x : p){
            cout << x.first << " " << x.second << endl;
        }
    }






    else if(!plus && minus){
        vector<P> p;
        reverse(ALL(a));
        int now = a[0], sum = 0;
        REP(i, 1, n - 1){
            p.emplace_back(now, a[i]);
            now = now - a[i];
        }

        cout << now << endl;
        for(auto x : p){
            cout << x.first << " " << x.second << endl;
        }
    }






    else {
        int MX = a[n - 1], MN = a[0];
        vector<P> p;
        int sum = 0;
        for(int i = 0; i < plus_num.size() - 1; i++){
            int pn = plus_num[i];
            p.emplace_back(MN, pn);
            MN -= pn;
        }

        for(int i = minus_num.size() - 1; i > 0; i--){
            int mn = minus_num[i];
            p.emplace_back(MX, mn);
            MX -= mn;
        }
        p.emplace_back(MX, MN);
        sum = MX - MN;
        for(int zn : zero_num){
            p.emplace_back(sum, zn);
        }

        cout << sum << endl;
        for(auto x : p){
            cout << x.first << " " << x.second << endl;
        }
    }


}