#include <iostream>
using namespace std;
int main(){
  string a;
  cin >> a;
  int flag = 0;
  for(int i = 0;i<a.size();i++){
    
    if(i%2==0){
      if(a.at(i)!='R'&&a.at(i)!='U'&&a.at(i)!='D') flag = 1;
    }
    else{
      if(a.at(i)!='L'&&a.at(i)!='U'&&a.at(i)!='D') flag = 1;
    }
  }
  if(flag)cout << "No";
  else cout << "Yes";
}