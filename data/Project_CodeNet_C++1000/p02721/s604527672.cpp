#include<iostream>
#include<string>
using namespace std;
int main(){
  int n,k,c;string s;cin>>n>>k>>c>>s;
  int* a=new int[k]{};
  int* b=new int[k]{};
  int ad=0;
  int bd=n-1;
  for(int i=0;i<k;i++){
    while(s[ad]!='o')ad++; a[i]=ad;ad+=c+1;
    while(s[bd]!='o')bd--; b[k-1-i]=bd;bd-=c+1;
  }
  for(int i=0;i<k;i++){
    if(a[i]==b[i]) cout<<a[i]+1<<endl;
  }
  return 0;
}
