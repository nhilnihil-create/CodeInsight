//02
#include<iostream>
#include<string>
#include<set>

using namespace std;

int main(){
  int n;
  cin>>n;
  set<string> s;
  while(n--){
    string t;
    cin>>t;
    s.insert(t);
  }
  int m;
  cin>>m;
  bool open=false;
  while(m--){
    string t;
    cin>>t;
    if(s.count(t)==0){
      cout<<"Unknown "<<t<<endl;
    }else{
      open=!open;
      cout<<(open?"Opened by ":"Closed by ")<<t<<endl;
    }
  }
  return 0;
}