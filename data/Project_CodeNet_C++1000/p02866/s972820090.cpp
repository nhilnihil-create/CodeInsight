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
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  VI D(N);
  rep(i,N) cin>>D[i];
  if(D[0]){
    cout<<0<<endl;
    return 0;
  }
  sort(all(D));
  ll ans=1;
  ll mod=998244353;
  rep(i,N-1){
    int X=D[N-1-i];
    int num=ub(all(D),X-1)-lb(all(D),X-1);
    ans=ans*num%mod;
  }
  cout<<ans<<endl;
}