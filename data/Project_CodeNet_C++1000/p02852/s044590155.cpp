#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)
typedef pair<int,int> P;
typedef long long ll;

int main() {
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  set<int> a;
  rep(i,0,n+1){
    if(s[i]=='0'){
      a.insert(i);
    }
  }
  stack<int> q;
  bool p=true;
  int cur=n;
  while(cur!=0){
    int next=*a.lower_bound(cur-m);
    if(next==cur){
      p=false;
      break;
    }
    else{
      q.push(cur-next);
      cur=next;
    }
  }
  if(p){
    while(q.size()){
      cout<<q.top()<<endl;
      q.pop();
    }
  }
  else{
    cout<<-1<<endl;
  }
}