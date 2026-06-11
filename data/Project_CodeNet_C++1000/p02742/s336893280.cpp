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
  ll h, w;cin>>h>>w;
  if(min(h, w)==1LL){
    cout<<1<<endl;
  }else if((h*w)%2!=0LL){
    cout<<h*w/2LL+1LL<<endl;
  }else{
    cout<<h*w/2LL<<endl;
  }
 //  system("read -n 1 -s -p \"Press any key to continue...\"");
}
