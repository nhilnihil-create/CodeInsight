#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using p=pair<int,int>;

int main(){
  int a,b;
  cin>>a>>b;
  
  string s1(a,'0'+b);
  string s2(b,'0'+a);
  
  cout<<min(s1,s2)<<endl;

return 0;
}
