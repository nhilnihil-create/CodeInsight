#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int K; cin >> K;
  queue<ll> Q;
  rep(i,9) Q.push(i+1);

  ll x;
  for (int i=1;i<=K;i++) {
    x = Q.front(); Q.pop();
    if (i==K) break;
    if (x%10!=0) Q.push(10*x+x%10-1);
    Q.push(10*x+x%10);
    if (x%10!=9) Q.push(10*x+x%10+1);
  }
  cout << x << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}
