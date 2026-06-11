#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int n=s.length();
  if(n%2==1){
    cout << "No" << endl;
    return 0;
  }
  for(int i=0;i<n;i+=2){
    if(s[i]!='h'||s[i+1]!='i'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}


