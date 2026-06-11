#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){
  if(a%b==0) return b;
  else return gcd(a,a%b);
}
ll lcm(ll a,ll b){
  ll g = gcd(a,b);
  return a/g*b;
}

int r,p,s;

int point(char c){
  int add = 0;
  if(c=='r') add = p;
  if(c=='p') add = s;
  if(c=='s') add = r;
  if(c=='n') add = 0;

  return add;
}

int main(){
  int n,k;
  cin >> n >> k >> r >> s >> p;
  string t;
  cin >> t;
  ll ans = 0;
  for(int i=k;i<n;i++){
    if(t.at(i-k)==t.at(i)) t.at(i) = 'n';
  }

  rep(i,n){
    ans+=point(t.at(i));
  }

  cout << ans << endl;
}
