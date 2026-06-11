#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back



int main(){
  
  ll n,k;
  cin>>n>>k;
  

  ll answer=0;
  
  for (ll i=k;i<=n+1;i++){
    ll up,down,tmp;
    down=((i-1)*i)/2;
    up=(i*(2*n-i+1))/2;
    tmp=(up-down+1)%MOD;
    answer+=tmp;
    answer%=MOD;
  }
  
  cout<<answer<<endl;
 
  
}




















