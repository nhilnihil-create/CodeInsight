#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


string s;
llint k;

void solve(){
  cin >> s;
  cin >> k;
  llint n=s.size();
  llint ans=0;
  llint cnt=1;
  for(int i=1;i<n;i++){
      if(s[i-1]==s[i])cnt++;
      if(s[i-1]!=s[i] && cnt>1){
          ans+=(cnt/2)*k;
          cnt=1;
      }
  } 
  if(n==cnt)ans+=(n*k)/2;
  else if(cnt>1)ans+=(cnt/2)*k;
  if(s[0]==s[n-1] && n!=cnt){
      llint a=0,b=0;
      for(;s[a]==s[0];a++);
      for(;s[n-b-1]==s[n-1];b++);
      ans-=(((a/2)+(b/2))-(a+b)/2)*(k-1);
  }
  cout << ans << endl; 
}

int main(){
  solve();
  return 0;
}
