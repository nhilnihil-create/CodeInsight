#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int q;
  cin >> s >> q;
  int i,x=1;
  deque<char> que;
  for(i=0;i<s.size();i++){
    que.push_back(s[i]);
  }
  for(i=0;i<q;i++){
    int a,b;
    char c;
    cin >> a;
    if(a==1){
      x*=-1;
      continue;
    }
    cin >> b >> c;
    if((b==1 && x==1) || (b==2 && x==-1)){
      que.push_front(c);
    }
    else{
      que.push_back(c);
    }
  }
  if(x==1){
    while(!que.empty()){
      cout << que.front();
      que.pop_front();
    }
  }
  else{
    while(!que.empty()){
      cout << que.back();
      que.pop_back();
    }
  }
  cout << endl;
}