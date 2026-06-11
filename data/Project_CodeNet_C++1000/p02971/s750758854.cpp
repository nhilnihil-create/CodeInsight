#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;

  vi a(n), b(n);
  rep(i,n){
    cin >> a.at(i);
    b.at(i) = a.at(i);
  }
  sort(a.begin(), a.end());
  
  int ans, sub;
  ans = a.at(n-1);
  sub = a.at(n-2);
  rep(i,n){
    cout << (ans==b.at(i)? sub : ans) << endl;
  }
  return 0;
}
