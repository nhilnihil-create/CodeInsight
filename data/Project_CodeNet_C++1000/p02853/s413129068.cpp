#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
const ll inf=1e9+7;
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }
ll lcm(ll a, ll b) { return a / (gcd(a, b)) * b; }

int main(){
  int x,y;
  cin>>x>>y;

  int ans;
  if(x==1 && y==1) ans=1000000;
  else ans=max(400000-x*100000,0)+max(400000-y*100000,0);

  cout<<ans<<endl;
}
