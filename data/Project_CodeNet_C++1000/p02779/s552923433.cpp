#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int n;
  string ans="YES";
  cin >> n;
  vi a(200000);
  rep(i, n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  rep(i, n-1){
    if(a[i]==a[i+1]){
      ans="NO";
      break;
    }
  }

  cout << ans << endl;

  return 0;
}