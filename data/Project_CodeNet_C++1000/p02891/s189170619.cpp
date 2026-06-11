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
  int k;cin>>k;
  int ans=0;
  vector<pair<char,int>> v=RL_S(s);
  int n=v.size();
  
  if(n==1){
    cout<<(s.length()*k)/2<<endl;
    return 0;
  }
  
  int m1=v[0].S,m2=v[n-1].S;
  if(v[0].F==v[n-1].F)ans+=((k-1)*((m1+m2)/2)+m1/2+m2/2);
  else ans+=k*((m1/2)+(m2/2));
  
  for(int i=1;i<n-1;i++){
    int l=v[i].S;
    ans+=k*(l/2);
  }
  cout<<ans<<endl;  
  return 0;
}