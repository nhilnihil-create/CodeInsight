#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str ;
  bool ans=true;
  for (int i=0;i<str.size();i+=2){
    if (str.size()%2==1){
      ans=false;
      break;
    }
    if (str.at(i)!='h' || str.at(i+1)!='i'){
      ans=false;
      break;
    }
  }
  string a= ans==true ? "Yes":"No";
  cout << a << endl;
}