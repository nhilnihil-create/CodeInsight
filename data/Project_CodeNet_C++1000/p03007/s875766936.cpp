#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n;
  cin >> n;
  vint A(n);
  rep(i,n) cin >> A[i];
  sort(A.begin(),A.end());
  int ans = 0;
  int positive = 0;
  int negative = 0;
  rep(i,n){
    if(i == 0) ans -= A[i];
    else if(i == n-1) ans += A[i];
    else{
      if(A[i] < 0) ans -= A[i];
      else ans += A[i];
    }
    if(A[i] > 0) positive++;
    else negative++;
  }
  cout << ans << endl;
  int tmp = 0;
  if(positive == 0){
    reverse(A.begin(),A.end());
    rep(i,n-1){
      if(i == 0){
        cout << A[i] << " " << A[i+1] << endl;
        tmp = A[i] - A[i+1];
      }
      else{
        cout << tmp << " " <<  A[i+1] << endl;
        tmp -= A[i+1];
      }
    }
  }
  else if(negative == 0){
    rep(i,n-1){
      if(i == 0){
        cout << A[i] << " " <<  A[i+1] << endl;
        tmp = A[i] - A[i+1]; 
      }
      else if(i == n-2){
        cout << A[i+1] << " " << tmp << endl;
      }
      else{
        cout << tmp << " " << A[i+1] << endl;
        tmp -= A[i+1];
      }
    }
  }
  else{
    for(int i = negative + 1;i < negative + positive;i++){
      if(i == negative + 1){
        cout << A[0] << " " <<  A[i] << endl;
        tmp = A[0] - A[i];
      }
      else{
        cout << tmp << " " << A[i] << endl;
        tmp -= A[i];
      }
      A[0] = tmp;
    }
    for(int i = 0;i < negative;i++){
      cout << A[negative] << " " << A[i] << endl;
      A[negative] -= A[i];
    }
  }
}