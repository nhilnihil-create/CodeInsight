#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  int group=1;
  rep(i,n-1){
    if(s[i]!=s[i+1]) group++;
  }
  cout<<n-1-max((group-1)-k*2,0)<<endl;
}
