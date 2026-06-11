#include<iostream>
using namespace std;
int main(){
int i;
  string s;
  cin >> s;
  int ans=0;
  for(i=0;i<s.size();i++){
  if(i%2==0 && s[i]=='L'){
cout << "No" << endl;
    return 0;
  }else if(i%2==1 && s[i]=='R'){
  cout << "No" << endl;
    return 0;
  }
  }
  cout << "Yes" << endl;
}