#include<iostream>
using namespace std;
int main(){
int n,i;
  string s;
  cin >> s;
  n= s.size();
  for(i=0;i<n;i++){
 s[i]='x';
  }
  cout << s << endl;
}