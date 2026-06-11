#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int A,B,m;
  cin >>A >>B >>m;
  vector<int> a(A), b(B);
  int amin = 1e8, bmin=1e8;
  rep(i,A) {
    cin >>a[i];
    amin = min(amin, a[i]);
  }
  rep(i,B) {
    cin >>b[i];
    bmin = min(bmin, b[i]);
  }
  int curMin = amin+bmin;
  rep(i,m){
    int x,y,c;
    cin >>x >>y >>c;
    int sum = a[x-1]+b[y-1]-c;
    curMin = min(curMin, sum);
  }
  cout << curMin << endl;
  return 0;
}