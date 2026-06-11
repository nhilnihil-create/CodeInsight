#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) { return a*b/gcd(a,b);}
ll MOD=1000000007;

int main(){
  int n;cin>>n;
  vector<string> s(n);
  vi t(n);
  rep(i,n){
    cin>>s.at(i)>>t.at(i);
  }
  string x;cin>>x;
  bool fl=false;
  int ans=0;
  rep(i,n){
    if(fl){
      ans+=t.at(i);
    }
    if(s.at(i)==x) fl=true;
  }
  cout<<ans<<endl;
}