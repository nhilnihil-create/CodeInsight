#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int ans=0;
  string t="000";
  rep(i,1000){
    int ti=0;
    rep(i,n){
      if(s[i]==t[ti]) ti++;
    }
    if(ti==3) ans++;
    if(t[2]=='9'){
      t[2]='0';
      if(t[1]=='9'){
        t[1]='0';
        t[0]++;
      }else t[1]++;
    }else t[2]++;
  }
  cout << ans << "\n";
  return 0;
}