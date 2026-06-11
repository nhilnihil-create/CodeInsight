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
  int N;
  cin>>N;
  vector<string> S(N);
  VI T(N);
  rep(i,N) cin>>S[i]>>T[i];
  string X;
  cin>>X;
  int ans=0;
  int F=0;
  rep(i,N){
    if(F) ans+=T[i];
    if(S[i]==X) F=1;
  }
  cout<<ans<<endl;
}