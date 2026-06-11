#include<stack>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
#include<algorithm>
#define rep(i,n) for(int i=0;(int) (n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
int main(){
  int n,p;
  string s;
  ll acm=0,ans=0,digit=1;
  cin >> n >> p >> s;
  reverse(s.begin(),s.end());
  if(p==2 || p==5){
    for(ll i=0;i<n;i++){
      if ((s[i]-'0')%p==0) ans+=n-i;
    }
  }
  else{
  map<int,ll> m;
  m[0]=1;
  for(auto str:s){
    acm+=(str-'0')*digit;
    acm%=p;
    m[acm]++;
    digit*=10;
    digit%=p;
  }
  for(auto i=m.begin();i!=m.end();i++){
    ans+=i->second*(i->second-1)/2;
  }
}
  cout << ans << endl;
  return 0;
}