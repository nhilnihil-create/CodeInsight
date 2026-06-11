#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;


int main(){
  ll n,m; cin >> n >> m; string s; cin >> s; reverse(all(s));
  ll now = 0; bool flag = true;
  stack<ll> num;

  while(flag){
    if(now == n) break; 
    
    flag = false;
    
    for(ll i=m; i > 0; i--){
      if(now + i <= n){
        if(s.at(now + i) == '0'){
        	num.push(i);
            now += i;
        	flag = true;
        	break;
        }
      }
    }
    
    if(!flag){
      cout << -1 << endl;
    }
  }
 
  if(flag){
    while(!num.empty()){
      cout << num.top() << ' ';
      num.pop();
    }
  }
}
