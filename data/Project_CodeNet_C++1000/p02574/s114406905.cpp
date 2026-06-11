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
    #include<numeric>
    #include<array>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
    #define Vl vector<ll>
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll ZER = 0;


//Osa_k法
vector<ll> sieve(ll n){
    vector<ll> res(n);
    iota(ALL(res), 0);
    for(int i = 2; i * i < n; i++){
        if(res[i] < i)continue;
        for(int j = i * i; j < n; j += i){
            if(res[j] == j)res[j] = i;
        }
    }
    return res;
}

vector<ll> factor(ll n, const vector<ll> & min_factor){
    //min_factorはsieve()で得られたもの
    vector<ll> res;
    while(n > 1){
        res.push_back(min_factor[n]);
        n /= min_factor[n];
    }
    return res;
}

//最大公約数
ll gcd(ll a, ll b){
    if(a % b == 0)return b;
    else return gcd(b, a % b);
}

int main(){
   int n;
   cin >> n;
   vector<ll> a(n);
   rep(i, n)cin >> a[i];

   ll GCD = a[0];
   rep(i, n){
       GCD = gcd(GCD, a[i]);
   }

   if(GCD != 1){
       cout << "not coprime" << endl;
       return 0;
   }

   auto mf = sieve(1000000);
   
   vector<ll> r;
   map<ll, ll> mp;
   rep(i, n){
       auto r = factor(a[i], mf);
       r.erase(unique(ALL(r)), r.end());
       int rs = r.size();
       rep(i, rs){
           mp[r[i]]++;

           if(mp[r[i]] > 1){
               cout << "setwise coprime" << endl;
               return 0;
           }
       }
   }
   cout << "pairwise coprime" << endl;
}
