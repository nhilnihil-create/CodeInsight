#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i,n){
    char c;
    cin >> c;
    s[i] = c - '0';
  }
  int ans = 0;
  rep(i,10){
    rep(j,10){
      rep(k,10){
        int p = 0;
        while(s[p] != i && p < n) p ++;
        p ++;
        while(s[p] != j && p < n) p ++;
        p ++;
        while(s[p] != k && p < n) p ++;
        if(p < n) ans ++;
      }//k
    }//j
  }//i
  cout << ans << endl;
}
