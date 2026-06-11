#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

vector<pair<char,int>> RL_S(string s){
  vector<pair<char,int>> res;
  int n=s.length();
  char ima;int cnt=0;
  rep(i,n){
    if(cnt==0){
      ima=s[i];
      cnt++;
    }
    else if(s[i]==ima)cnt++;
    else{
      res.pb(make_pair(ima,cnt));
      ima=s[i];
      cnt=1;
    }
  }
  res.pb(make_pair(ima,cnt));
  return res;
}

int a[100010];
signed main(){
  string s;cin>>s;
  int ima=0;
  for(auto p:RL_S(s)){
    char c=p.F;int ko=p.S;
    if(c=='R'){
      a[ima+ko-1]+=(ko+1)/2;
      a[ima+ko]+=ko/2;
    }
    if(c=='L'){
      a[ima]+=(ko+1)/2;
      a[ima-1]+=ko/2;
    }
    ima+=ko;
  }
  int n=s.length();
  rep(i,n)cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}