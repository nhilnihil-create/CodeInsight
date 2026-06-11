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

  map<int, int> a;
  rep(i,n){
    int ai;
    cin >> ai;
    a[ai] = i + 1;
  }

  for (auto ele : a){
    cout << ele.second << endl;
  }
  return 0;
}
