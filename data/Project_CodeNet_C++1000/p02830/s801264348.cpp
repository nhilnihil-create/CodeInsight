#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int main(){
  int n;cin>>n;
  string s,t;cin>>s>>t;
  for(int i=0;i<2*n;i++){
    if(i%2==0)cout<<s[i/2];
    else cout<<t[i/2];
  }
  cout<<endl;
  return 0;
}