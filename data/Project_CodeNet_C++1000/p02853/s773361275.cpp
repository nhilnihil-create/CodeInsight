#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int X,Y;
  cin>>X>>Y;
  int ans=0;
  if(X==3) ans+=100000;
  else if(X==2) ans+=200000;
  else if(X==1) ans+=300000;
  if(Y==3) ans+=100000;
  else if(Y==2) ans+=200000;
  else if(Y==1) ans+=300000;
  if(X*Y==1) ans+=400000;
  cout<<ans<<endl;
}