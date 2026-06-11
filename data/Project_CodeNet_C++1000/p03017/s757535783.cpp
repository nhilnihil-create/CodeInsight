#include <iostream>
using namespace std;

int main(){
  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string str;
  cin >> str;
  int cnt=0;
  for(int i=a; i<=c; i++){
    if(str[i]=='#'){
      cnt++;
      if(cnt==2){
        cout << "No" << endl;
        return 0;
      }
    }else{
      cnt = 0;
    }
  }
  cnt=0;
  for(int i=b; i<=d; i++){
    if(str[i]=='#'){
      cnt++;
      if(cnt==2){
        cout << "No" << endl;
        return 0;
      }
    }else{
      cnt = 0;
    }
  }
  if(c<d){
    cout << "Yes" << endl;
    return 0;
  }
  cnt =0;
  for(int i=b-1; i<=d+1; i++){
    if(str[i]=='.'){
      cnt++;
      if(cnt==3){
        cout << "Yes" << endl;
        return 0;
      }
    }else{
      cnt = 0;
    }
  }
  cout << "No" << endl;
  return 0;
}



