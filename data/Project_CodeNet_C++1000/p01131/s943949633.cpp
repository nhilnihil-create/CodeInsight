#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i,j,k;
  int a[9]={5,3,3,3,3,3,4,3,4},n;
  int ln;
  char c[9][6]={".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  string s;
  string *t;
  cin>>n;
  t=new string[n];
  for(i=0;i<n;i++){
    cin>>s;
    ln=s.length();
    t[i]="";
    for(j=0;j<ln;j=k){
      for(;j<ln&&s[j]=='0';j++);
      for(k=j;k<ln&&s[j]==s[k];k++);
      if(k-j)
	t[i]+=c[s[j]-'1'][(k-j-1)%a[s[j]-'1']];
    }
  }
  for(i=0;i<n;i++)
    cout<<t[i]<<endl;
  delete[]t;
  return 0;
}