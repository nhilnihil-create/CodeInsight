#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<pair<ll,ll>>>;

int main(){
  int n,k; cin>>n>>k;
  string s; cin>>s;
  int score = 0;
  rep(i,n-1){
    if(s.at(i)==s.at(i+1))score++;
  }
  int res = min(score+2*k,n-1);
  cout<<res<<endl;
}