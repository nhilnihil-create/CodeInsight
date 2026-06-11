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
  ll a, v, b, w, t;cin>>a>>v>>b>>w>>t;

  if(v<=w){cout<<"NO"<<endl;return 0;}
  cout<<(abs(a-b)<=t*(v-w)?"YES":"NO")<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
