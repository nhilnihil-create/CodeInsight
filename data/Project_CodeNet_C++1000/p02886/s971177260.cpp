#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int n, sum=0, ans=0;
  cin >> n;
  vi d(n);
  rep(i, n){
    cin >> d[i];
    sum+=d[i];
  }

  rep(i, n){
    ans+=(sum-d[i])*d[i];
  }

  cout << ans/2 << endl;

  return 0;
}