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
        int posI = -1;
        rep(p,n){
          if(s[p] == i){
            posI = p;
            break;
          }
        }
        if(posI == -1) continue;
        int posJ = -1;
        for(int p=posI+1;p<n;p++){
          if(s[p] == j){
            posJ = p;
          	break;
          }
        }
        if(posJ == -1) continue;
        for(int p=posJ+1;p<n;p++){
          if(s[p] == k){
            ans ++;
            break;
          }
        }
      }//k
    }//j
  }//i
  cout << ans << endl;
}