#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string tmp;
  string a = s.substr(0,(s.size()-1)/2);
  string b = s.substr((s.size()+3)/2-1,s.size()-(s.size()+3)/2+1);
  int ans = 1;
  tmp = a;
  reverse(a.begin(), a.end());
  if(tmp != a){
    ans = 0;
  }
  tmp = b;
  reverse(b.begin(), b.end());
  if(tmp != b){
    ans = 0;
  }
  tmp = s;
  reverse(s.begin(), s.end());
  if(tmp != s){
    ans = 0;
  }
  
  if(ans == 1){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl; 
  }
}