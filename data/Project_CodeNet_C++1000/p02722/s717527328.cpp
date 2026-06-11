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
#define INF 100000000000000009
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

vector<P> prime_factorize(int a){
  vector<P> ans;
  for(int i = 2;i*i <= a;i++){
    int num = 0;
    if(a % i == 0){
      while(a % i == 0){
        num++;
        a /= i;
      }
      ans.push_back(make_pair(i,num));
    }
  }
  if(a != 1) ans.push_back(make_pair(a,1));
  return ans;
}
signed main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 2;i <= sqrt(n);i++){
    if(n % i != 0 && (n-1) % i == 0){
      if((n-1)/i==i)ans++;
      else ans+=2;
    }
    else{
      int temp = n;
      while(temp % i == 0){
        temp /= i;
      }
      if(temp == 1)ans++;
      else if((temp - 1) % i == 0)ans++;
    }
  }
  if(n == 2) ans--;
  cout << ans + 2 << endl;
}