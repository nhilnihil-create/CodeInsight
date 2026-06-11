#include <bits/stdc++.h>
using namespace std;

int main() {
    string T;
    cin >> T;
  int n=T.size();
  vector<string> a(n);
  
  for(int i=0; i < n; i++){
  a.at(i)=T[i];  
  }
  
  
  for (int i=0; i < n; i++){
    if(a.at(i)=="?"){
      a.at(i)="D";
     }
     }
  
string Z="";
  
 for (int i =0; i<n;i++){
   Z += a.at(i);
 }
  
  cout << Z << endl;
  
  }
  