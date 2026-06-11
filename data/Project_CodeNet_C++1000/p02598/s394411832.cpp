#include <bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
   int n, k;
   cin >> n >> k ;
   vi a(n);
   rep(i, n) cin >> a.at(i);
   //二分探索
   int l = 0, r = 1e9;
   while(r-l > 1) {
       int x = (l+r)/2;
       auto f = [&](int x) {
           ll now = 0;
           //丸太を切る回数を求める
           rep(i, n) now += (a.at(i)-1)/x;
           return now <= k;
       };
       if (f(x)) r = x; else l = x;
   }
   cout << r << endl;
   return 0;
}