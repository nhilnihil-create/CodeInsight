#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const int INF=1e9;

int n;

int main(){
  string s,t,u;
  int a,b;
  cin>>s>>t;
  cin>>a>>b;
  cin>>u;
  
  
  if(s==u) a--;
  if(t==u) b--;
  cout<<a<<" "<<b<<endl;
  return 0;
  
 
  

}