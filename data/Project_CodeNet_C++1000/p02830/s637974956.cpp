#include<iostream>
#include<string>
using namespace std;
int main(){
  char ch[100],s[100],str[200];
  int n=0,i=0,j=0;
  cin>>n;
  cin.ignore();
  cin>>ch;
  cin>>s;
  while(i<n){
    str[j]=ch[i];
    j++;
    str[j]=s[i];
    j++;
    i++;
  }
  for(i=0;i<(2*n);i++)
    cout<<str[i];
}