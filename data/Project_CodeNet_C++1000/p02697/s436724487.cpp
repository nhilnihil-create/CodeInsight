#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,m;
  cin>>n>>m;
  int a=1,b=n;
  if(n%2==1){
    rep(i,m){
      cout<<a<<" "<<b<<endl;
      a++; b--;    
    }
  }
  else{
    bool ok=false;
    rep(i,m){
      cout<<a<<" "<<b<<endl;
      a++; b--;
      if(b-a<=n/2&&!ok)b--,ok=true;
    }
  }
}