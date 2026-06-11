#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i,j,k,l;
  int n,s[22050];
  s[0]=2;
  j=1;
  for(i=3;i<250000;i+=2){
    l=(int)sqrt(i)+1;
    for(k=3;k<l;k+=2){
      if(i%k==0)
	break;
    }
    if(k>=l){
      s[j]=i;
      j++;
    }
  }
  while(cin>>n&&n){
    for(i=0;s[i]<=n;i++);
    for(j=i;s[j]<=2*n;j++);
    cout<<j-i<<endl;
  }
  return 0;
}