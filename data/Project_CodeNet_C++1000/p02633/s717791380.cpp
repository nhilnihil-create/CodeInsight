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

int gcd(int x, int y){
  if(x==0)return y;
  return gcd(y%x, x);
}

int main(){
  int x;cin>>x;
  cout<<360/gcd(x, 360)<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
