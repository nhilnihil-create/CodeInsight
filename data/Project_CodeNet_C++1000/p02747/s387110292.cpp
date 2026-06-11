#include <bits/stdc++.h>
using namespace std;
int main()
{
 string s;
  cin >>s;
 if(s.size()%2==0){
 for(int i=0;i<s.size();i+=2){
  if(s[i]!='h'||s[i+1]!='i'){
  cout << "No";
  return 0;
  }
 }
 }else{
 cout << "No";
   return 0;
 }
 cout << "Yes";
}