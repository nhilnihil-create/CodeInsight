#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

   int n;
  cin >> n;
  vi a(n), ans(n);
  rep(i, n){
    cin >> a[i];
    ans[a[i]-1]=i+1;
  }
 
  rep(i, n)cout << ans[i] << " ";
  cout << "\n";

  return 0;
}