#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  char str1[101],str2[101];
  string str;
  cin>>n;
  cin>>str1>>str2;

  for(int i=0;i<n;i++){
    str+=str1[i];
    str+=str2[i];
  }
  cout<<str<<endl;
  return 0;
}
