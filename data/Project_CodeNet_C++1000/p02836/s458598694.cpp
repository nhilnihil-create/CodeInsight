#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >>s;
  int p;
  for(int i=0;i<s.size();i++){
    if(s[i]!=s[s.size()-i-1]) p++;
  }
  cout << p/2 <<endl;
  
}
  