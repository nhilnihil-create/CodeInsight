#include<bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
// using namespace atcoder;

const ll mod=1000000007;//998244353;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n;
  cin >> n;
  vec t(30);
  t[0]=1;
  for(ll i=0;i<29;i++)t[i+1]=t[i]*2;
  ll m=t[n];
  multiset<ll,greater<ll>> s;//これから生まれるべきスライム
  for(ll i=0;i<m;i++){
    ll a;
    cin >> a;
    s.insert(a);
  }
  s.insert(-1);
  
  bool ok=true;
  multiset<ll,greater<ll>> b;//既に生まれたスライム
  ll c=*s.begin();
  b.insert(c);
  s.erase(s.lower_bound(c));

  for(ll i=0;i<n;i++){
    ll a=t[i];
    vec q;
    for(ll j=0;j<a;j++){
      ll c=*b.begin();
      b.erase(b.lower_bound(c));
      q.push_back(c);
      ll d=*s.upper_bound(c);
      if(d==-1){
        ok=false;
        break;
      }
      q.push_back(d);
      s.erase(s.lower_bound(d));
    }
    for(ll j=0;j<q.size();j++){
      b.insert(q[j]);
    }
    if(!ok)break;
  }
  if(ok)cout << "Yes" << endl;
  else cout << "No" << endl;

  //for(ll i=0;i<m;i++)cout << s[i] << " ";


  return 0;
}