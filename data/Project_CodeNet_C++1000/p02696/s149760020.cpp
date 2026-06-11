#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

ll a,b,n;

ll floor(ll N){
  ll fl1 = a*N/b;
  ll fl2 = N/b;
  ll sum = fl1 + a*fl2;
  return sum;
}

int main(){
  cin >>a >>b >>n;
  cout << floor(min(b-1,n)) << endl;
  return 0;
}
