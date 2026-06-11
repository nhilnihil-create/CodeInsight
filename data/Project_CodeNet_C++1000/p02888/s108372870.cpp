#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi l(n);
  rep(i,n) cin >> l[i];
  sort(l.begin(),l.end());
  ll ans = 0;
  for(int a=n-1; a>1; a--){
    for(int b=a-1; b>0; b--){
      int dif = l[a]-l[b];
      int left = -1, right = b;
      while(right-left>1){
        int mid = (left+right)/2;
        if(l[mid] > dif) right = mid;
        else left = mid;
      }
      ans += b-right;
      //cout << right << endl;
    }
  }
  cout << ans << endl;
}
