#include <bits/stdc++.h>
using namespace std;

int main(){

string a;
cin >> a;
  int sum = 0;
  int len = a.size();
  for(int i=0;i<len;i++){
  sum += a[i]-48;
  }
  if(sum % 9 ==0)
     cout << "Yes"; 
  else
     cout << "No";
  return 0;
}