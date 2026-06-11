#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int main(){
  string s;cin>>s;
  bool flag=false;
  if(s=="hi")flag=true;
  if(s=="hihi")flag=true;
  if(s=="hihihi")flag=true;
  if(s=="hihihihi")flag=true;
  if(s=="hihihihihi")flag=true;
  
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}