#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
typedef pair<int,int> pii;
typedef vector<int> vi;
void solve(){
  string s;
  cin>>s;
  int n = s.length();
  vi ans(n+1);
  for(int i = 0;i<n;i++){
    if(s.at(i)=='<')
    ans[i+1] = max(ans[i+1],ans[i]+1);
  }

  for(int i = n-1;i>=0;i--){
    if(s.at(i)=='>'){
      ans[i] = max(ans[i],ans[i+1]+1);
    }
  }
  lli tot = 0;
  for(int i = 0;i<=n;i++){
    tot+=ans[i];
  }
  cout<<tot;
  
}

int main(){
  solve(); 
}