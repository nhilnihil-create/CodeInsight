#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

int n;
void dfs(string s,char mx){
  if(s.size() == n){
    cout << s << endl;
    return ;
  }
  for(char c = 'a';c <= mx;c++){
    if(c == mx)dfs(s+c,mx+1);
    else dfs(s+c,mx);
  }
}

int main(){

  cin >> n;
  dfs("a",'b');
  
  




  return 0;
}