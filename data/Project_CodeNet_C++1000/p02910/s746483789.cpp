#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  for(int i=0;i<s.size();i++){
    if(i%2==1){
      if('R'==s[i]){
        cout << "No" << endl;
        return 0;
      }
    }else{
      if('L'==s[i]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}