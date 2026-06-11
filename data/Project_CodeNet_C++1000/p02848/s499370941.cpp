#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  for(int i = 0;i < s.size();i++){
    cout << (char)( ( (int)s[i]+n-(int)'A')%('Z'-'A'+1)+(int)'A') ;
  }
  cout << endl;
}