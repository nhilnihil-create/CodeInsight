#include<bits/stdc++.h>
using namespace std;
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  list<int> l;
  for(int i=0;i<n;i++){
    string s;
    int x;
    cin>>s;
    if(s=="insert"||s=="delete") cin>>x;
    if(s=="deleteFirst"){
      l.pop_front();
      continue;
    }
    if(s=="deleteLast"){
      l.pop_back();
      continue;
    }
    if(s=="insert"){
      l.push_front(x);
      continue;
    }
    if(s=="delete"){
      auto it=find(l.begin(),l.end(),x);
      if(it==l.end()) continue;
      l.erase(it);
      continue;
    }
  }
  bool f=0;
  for(auto it=l.begin();it!=l.end();++it){
    if(f) cout<<" ";
    cout<<*it;
    f=1;
  }
  cout<<endl;
  return 0;
}