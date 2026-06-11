#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<double> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(),v.end());
  rep(i,n-1){
    double a = v[0], b = v[1];
    v[1] = 10000;
    v[0] = (a+b)/2;
    sort(v.begin(),v.end());
  }
  cout << v[0] << endl;
}
