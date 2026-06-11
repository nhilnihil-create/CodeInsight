#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n){
    int ia, ib;
    cin >> ia >> ib;
    a.at(i) = ia; b.at(i) = ib;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if(n % 2 == 1){
    int l = a.at(n/2);
    int r = b.at(n/2);
    cout << r - l + 1 << endl;
  }else{
    int l = (a.at(n/2-1) +a.at(n/2));
    int r = (b.at(n/2-1) +b.at(n/2));
    cout << r - l + 1 << endl;
  }
  return 0;
}