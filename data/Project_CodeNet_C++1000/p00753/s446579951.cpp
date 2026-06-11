#include<bits/stdc++.h>
using namespace std;
#define OUT(x) cout<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x
const int BA = 1000;
const int INFTY = (1<<21);
int main(){
  const int MAXN = 123456*2;
  int par[MAXN];
  int n,ans;
  memset(par,1,sizeof(par));
  for(int i=2;i<sqrt(MAXN);i++){
    if(par[i]){
      for(int j=0;i*(j+2)<MAXN;j++){
	par[i*(j+2)]=0;
      }
    }
  }
  while(cin >> n&&n){
    ans = 0;
    for(int i=n+1;i<=2*n;i++){
      if(par[i])ans++;
    }
    OUT(ans);
  }
}