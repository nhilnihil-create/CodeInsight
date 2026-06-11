#include<bits/stdc++.h>
using namespace std;

bool judge(int s){
  for(int i=2;i*i<=s;i++){
    if(s%i!=0 && (i+1)*(i+1)>s){return true;}
    if(s%i==0){return false; break;}
    }
}


int main(){
  unsigned long long a;
  int m,n,b;
  cin>>m>>n;
  a=m;
  b=1000000007;


  int l=n;
  int k[1000]={};

  if(judge(l)){k[0]=l;}

  else{
    int count=0;
    for(int j=2;;){
      if(l==1){break;}
      if(l%j==0){l=l/j; k[count]=j; count++; continue;}
      j++;
    }}




  for(int j=0;k[j]!=0;j++){
    for(int i=1;i<k[j];i++){
      a=a*m;
      if(a>=b){a=a%b; if(a==m && k[j]-i>k[j]%i){k[j]=k[j]%i; i=0;}  if(a==1){break;}}
  }
    m=a;
  }

  cout<<a<<endl;
 
  return 0;
}

