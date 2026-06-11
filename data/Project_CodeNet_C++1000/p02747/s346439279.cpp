#include <bits/stdc++.h>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


int main(){
  string s;
  string h = "hi";
  cin >>s;
  if(s.size()%2==1){
    cout<<"No"<<endl;
    return 0;
  }
  bool flag =true;
  for(int i =0;i<s.size();i++){
    char x =s.at(i);
    if(i%2==0){
      if(x != 'h')flag =false;
    }
    if(i%2==1){
      if(x != 'i')flag =false;
    }
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}