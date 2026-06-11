#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll K;
  cin>>K;
  
  ll count=0;
  queue<string> S;
  S.push("1");
  S.push("2");
  S.push("3");
  S.push("4");
  S.push("5");
  S.push("6");
  S.push("7");
  S.push("8");
  S.push("9");
  string ans;

  while(count<K) {
    string W=S.front();
    S.pop();
    count++;
    if(count==K) {
ans=W;
    }
    for(ll i=W.back()-'0'-1;i<=W.back()-'0'+1;i++) {
if(i<0||i>9) {
continue;
}
   S.push(W+to_string(i));
    }
  }
  
  cout<<ans<<endl;
}
   


  
  
  
