#include <bits/stdc++.h>
using namespace std;

int main() {
  
  //sが回分∧(n-1)/2のとこも回分∧(n+3)/2も回分
  
  string s;
  cin >> s;
  
  int size = s.size();
  int t = size - 1; 
  
  int ans = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  for(int i = 0; i < size; i++){
    int k = t - i;
    if(s.at(i) == s.at(k)) a++;
  }
  if(a == size) ans++;
  
  
  for(int i = 0; i < t/2; i++){
    int k = t - i;
    if(s.at(i) == s.at(k)) b++;
  }
  if(b ==  t/2) ans++;
  
  int d = (size + 3)  / 2 - 1;
  int p = size - 1;
  for(int i = d; i < size; i++){
    if(s.at(i) == s.at(p)) c++;
    p--;
  }
  int q = size - d ;
  if(c == q) ans++;
  
  if(ans == 3){
    
    cout << "Yes" << endl;
    

  }
  else{
    cout << "No" << endl;
  }
}

