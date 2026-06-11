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
  int n, k;cin>>n>>k;
  vector<bool> snuke(n, false);
  rep(i, k){
    int d;cin>>d;
    rep(j, d){
      int a;cin>>a;
      snuke[--a]=true;
    }
  }
  int cnt = 0;
  rep(i, n){
    if(!snuke[i])cnt++;
  }
  cout<<cnt<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
