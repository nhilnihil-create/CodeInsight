#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s[0]==s[1]){
    cout << "Bad" << endl;
  }
  else if(s[1]==s[2]){
    cout << "Bad" << endl;
  }
  else if(s[2]==s[3]){
    cout << "Bad" << endl;
  }
  else if(s[0]==s[1] && s[0]==s[2] && s[0]==s[3]){
    cout << "Bad" << endl;
  }
  else{
    cout << "Good" << endl;
  }
    
//aaab
//aaba
//abaa
//baaa


}