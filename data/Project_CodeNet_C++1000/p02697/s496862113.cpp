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
     
    #define INF 1e10
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
       int n, m;
       cin >> n >> m;
       int d = 0;
       rep(i, m){
          if(n % 2 == 0){
             int j = n - i;
             if(2 * (j - i - 1) == n){d = 1;j -= d;}
             if(m / 2 < i)j = j -  1;
             //cout << i + 1 << " " << j << "   " << j - i - 1 << " " << n - (j - i - 1) << endl;
            cout << i + 1 << " " << j << endl;
          }
          else cout << i + 1 << " " << n - i - 1 << endl;
       }
    }



