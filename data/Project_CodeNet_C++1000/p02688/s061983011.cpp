#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n, k; cin >> n >> k;
  vector<int> a(n, 0);
  while (k--){
    int d;  cin >> d;
    for (int i = 0; i < d; ++i){
      int idx;  cin >> idx; idx--;
      a[idx] = 1;
    }
  }
  cout << count(a.begin(), a.end(), 0) << "\n";
  return 0;
}