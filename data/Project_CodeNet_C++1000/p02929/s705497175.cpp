#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;
typedef unsigned long long ull;



int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ans=1;
  rep(i,n) (ans*=(i+1))%=MOD;
  ll l=0,r=0;
  rep(i,n*2){
    int k;
    k=i%2;
    if (s[i]=='B'){
      if (k) {
        r++;
        (ans*=l)%=MOD;
        l--;
      }
      else l++;
    }
    else{
      if (k){
        l++;
      }
      else{
        r++;
        (ans*=l)%=MOD;
        l--;
      }
    }
  }
  if (r!=n) ans=0;
  cout << ans << endl;
}
