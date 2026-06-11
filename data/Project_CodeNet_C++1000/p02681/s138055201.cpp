#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  int count=0;
  if(s.size()+1==t.size()){
    for(int i=0;i<s.size();i++){
      if(s.at(i)==t.at(i))count++;
      if(count==s.size()){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}