#include <iostream>
using namespace std;

int main(void)
{
  int k,a[1000],b[1000],c;
  string s[1000];

  k=0;
  do{
    k=k+1;
    cin >> a[k] >> s[k] >> b[k];
  }while(s[k] != "\?");

  k=1;
  while(s[k]!="\?"){
    if(s[k]=="+") c=a[k]+b[k];
    if(s[k]=="-") c=a[k]-b[k];
    if(s[k]=="*") c=a[k]*b[k];
    if(s[k]=="/") c=a[k]/b[k];
    cout << c << endl;
    k=k+1;
  };

  return 0;
}