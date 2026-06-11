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
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000000000000
using P = pair<int,int>;
 
int main() {
  ll n;
  cin >> n;
  vll A(n);
  rep(i,n){
    cin >> A[i];
  }
  vll front(n);
  vll back(n);
  front[0] = A[0];
  rep1(i,n){
    front[i] = front[i-1] + A[i];
  }
  back[n-1] = A[n-1];
  for(int i = n-2;i >= 0;i--){
    back[i] = back[i+1] + A[i];
  }
  ll ans = INF;
  rep(i,n-1){
    ans = min(ans,abs(front[i] - back[i+1]));
  }
  cout << ans << endl;
}