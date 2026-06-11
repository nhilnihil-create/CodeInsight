#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++){
    ans = ans +  int(s.at(i))-48;
  }
  if (ans%9==0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

