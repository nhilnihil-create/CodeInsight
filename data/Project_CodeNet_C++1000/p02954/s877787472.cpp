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
  vi ltrap(n);
  for(int i = 1;i<=n-1;i++){
    if(s.at(i)=='L'){
      if(s.at(i-1)=='R'){
        ltrap[i] = i-1;
      }
      else{
        ltrap[i] = ltrap[i-1];
      }
    }
  }
  vi rtrap(n);
  for(int i = n-2;i>=0;i--){
    if(s.at(i)=='R'){
      if(s.at(i+1)=='L'){
        rtrap[i] = i+1;
      }
      else{
        rtrap[i] = rtrap[i+1];
      }
    }
  }

  vector<lli> ans(n);
  for(int i = 0;i<n;i++){
    if(s.at(i)=='L'){
      int tr = ltrap[i];
      int dist = abs(i-tr);
      if(dist%2==0){
        ans[tr]++;
      }
      else{
        ans[tr+1]++;
      }

    }

    else{
      int tr = rtrap[i];
      int dist = abs(tr-i);
      if(dist%2==0){
        ans[tr]++;
      }
      else{
        ans[tr-1]++;
      }
    }

  }

  for(int i = 0;i<n;i++){
    cout<<ans[i]<<" ";
  }
  

}


int main(){
  solve(); 
}