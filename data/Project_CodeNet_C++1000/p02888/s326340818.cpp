#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> L(n);
  rep(i,n) cin >> L[i];
  sort(L);
  int ans = 0;
  rep(i,n-1){
    for(int j=i+1;j<n;j++){
      int ng = n;
      int ok = j;
      while(abs(ng-ok)>1){
        int mid = (ok+ng)/2;
        if(L[mid] >= L[i]+L[j]) ng = mid;
        else ok = mid;
      }
      ans += ok - j;
    }
  }
  cout << ans << endl;
}