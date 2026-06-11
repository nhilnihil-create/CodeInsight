#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int i = 0;
  while(i<n){
    for(int i = 0; i<s.size(); i++){
      if(s.at(i) != 'Z')
       s.at(i)++;
      else{
        s.at(i) = 'A';
      }
    }
    i++;
  }
  cout << s << endl;
}