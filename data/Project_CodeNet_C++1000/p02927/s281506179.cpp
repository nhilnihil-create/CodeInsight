#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

int main(){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  rep(i,b+1)if(i/10>=2 && i%10>=2){
   if((i/10)*(i%10)<=a) ans++; 
  }
  cout << ans << endl;

  return 0;
}