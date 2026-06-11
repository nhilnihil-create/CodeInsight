#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<(n);i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main(){
  string s,t;
  int i,ans=0;
  cin >> s >> t;
  for(i=0;i<s.size();i++){
  if(s.at(i)==t.at(i)){
  ans++;
  }
  }
  cout << ans << endl;
}
