#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> v1(n);
  vector<bool> ok(n,true);
  int mx = 0;
  
  REP(i,n){
    cin >> v[i];
    v1[i] = v[i];
  }
  sort(v1.begin(),v1.end());
  REP(i,n){
    if(v[i] != v1[n-1]){
      mx = max(mx,v[i]);
    }
  }
  
  if(v1[n-1] == v1[n-2]){
    REP(i,n){
      cout << v1[n-1] << endl;
    }
  }
  else{
    REP(i,n){
      if(v[i] == v1[n-1]){
        cout << mx << endl;
      }
      else{
        cout << v1[n-1] << endl;
      }
    }
  }
	
  
  
}