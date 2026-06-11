#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  ll x;  cin >> x;
  int N = 1e3;
  for (int i = -N; i <= N; ++i){
    for (int j = -N; j <= N; ++j){
      ll now = (1LL*i*i*i*i*i) - (1LL*j*j*j*j*j);
      if(now==x){
        cout << i << " " << j << "\n";
        return 0;
      }
    }
  }
  return 0;
}