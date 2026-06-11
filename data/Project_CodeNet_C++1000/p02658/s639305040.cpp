/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 10000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int main(){
  int n;cin>>n;
  ll ans=1LL;
  bool inf=false;
  rep(i, n){
    ll a;cin>>a;
    if(a==0LL){cout<<0<<endl;return 0;}
    ll d=ll(1e18)/ans;
    if(d<a){inf=true;ans=1LL;}
    ans*=a;
  }
  cout<<(inf?-1:ans)<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
