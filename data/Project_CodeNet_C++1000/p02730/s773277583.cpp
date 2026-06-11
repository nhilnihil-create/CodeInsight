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
  string s;cin>>s;
  int n = (int)s.size();
  int m = n/2;
  bool ans = true;
  rep(i, n/2){
    if(s[i]!=s[n-i-1])ans=false;
  }
  string t;t=s.substr(0, m);
  rep(i, m/2){
    if(t[i]!=t[m-i-1])ans=false;
  }
  cout<<(ans?"Yes":"No")<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
