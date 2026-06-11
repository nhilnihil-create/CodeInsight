#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b)
#define chmin(a, b) (a)=min(a, b)
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

vector<ll> zalgorithm(string s) {
  ll N=s.size();
  vector<ll> res(N);
  res[0]=N;
  ll i=1, j=0;
  while(i<N) {
    while(i+j<N && s[j]==s[i+j]) j++;
    res[i]=j;
    if(j==0) {i++; continue;}
    ll k=1;
    while(i+k<N && k+res[k]<j) {res[i+k]=res[k]; k++;}
    i+=k; j-=k;
  }
  
  return res;
}


int main(){
  ll i, j, k;
  
  ll N;
  cin >> N;
  string s;
  cin >> s;
  
  ll ans=0;
  for(i=0; i<N; i++) {
    string t=s.substr(i);
    vector<ll> lcp=zalgorithm(t);
    
    for(j=0; j<t.size(); j++) chmax(ans, min(lcp[j], j));
  }
  
  pt(ans);
}


