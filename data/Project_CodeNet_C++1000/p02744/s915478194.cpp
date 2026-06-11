#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
int n;

void dfs(string s, char mx){
  if(s.length()==n){
    cout<<s<<endl;
    
  }else{
    for(char c='a'; c<=mx;c++){
      dfs(s+c, ((c==mx)? (char)(mx+1): mx));
    }
  }
}

int main(){
  cin >>n;
  dfs("",'a');
  return 0;

}