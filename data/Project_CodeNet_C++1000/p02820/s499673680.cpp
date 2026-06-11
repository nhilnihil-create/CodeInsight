#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,k,r,s,p;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  queue<char> q;
  int ans=0;
  rep(i,n){ 
    if(i < k){
      if(t[i]=='r') {q.push('p'); ans+=p;} 
      if(t[i]=='s') {q.push('r'); ans+=r;}
      if(t[i]=='p') {q.push('s'); ans+=s;}
    }else{
      if(t[i]=='r'){
        if(q.front()!='p') {q.push('p'); ans+=p;}
        else q.push('a');
        q.pop();
      }
      if(t[i]=='s'){
        if(q.front()!='r') {q.push('r'); ans+=r;}
        else q.push('a');
        q.pop();
      }
      if(t[i]=='p'){
        if(q.front()!='s') {q.push('s'); ans+=s;}
        else q.push('a');
        q.pop();
      }
    }
  }
  cout<<ans<<endl;
}