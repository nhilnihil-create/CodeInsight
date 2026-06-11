#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,b;
  list<int>a;
  cin>>n;
  string s;
  while(n--){
    cin>>s;
    if(s.size()<=6){
      cin>>b;
      if(s[0]=='i')a.push_front(b);
      else{
        list<int>::iterator it=a.begin();
        while(it!=a.end()){
          if(*it==b){a.erase(it);break;}
          it++;
        }
      }
    }
    else{
      if(s[6]=='F')a.pop_front();
      else a.pop_back();
    }
  }
  list<int>::iterator it=a.begin();
  for(int i=0;it!=a.end();it++,i++){
    if(i)cout<<' ';
    cout<<(*it);
  }
  cout<<endl;
}