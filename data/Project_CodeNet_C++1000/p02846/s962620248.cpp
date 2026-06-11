#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  ll T1,T2,A1,A2,B1,B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  ll X=A1-B1;
  ll Y=A2-B2;
  if(X<0){
    X=-X;
    Y=-Y;
  }
  ll P=X*T1;
  ll Q=Y*T2;
  if(P+Q==0) cout<<"infinity"<<endl;
  else if(P+Q>0) cout<<0<<endl;
  else{
    ll R=P/(-P-Q);
    if(P%(-P-Q)) cout<<2*R+1<<endl;
    else cout<<2*R<<endl;
  }
}