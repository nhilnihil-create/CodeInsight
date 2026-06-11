#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  string b;
  cin >> b;
  for(int i = 0;i < b.length() && i < a;i++)
  {
    cout << b[i];
  }
  if(a < b.length()){
    cout << "...";
  }
  return 0;
}