#include<bits/stdc++.h>
using namespace std;

bool judge(int s){
  for(int i=2;i*i<=s;i++){
    if(s%i!=0 && (i+1)*(i+1)>s){return true;}
    if(s%i==0){return false; break;}
    }
}


int main(){

  int n,l;
  cin>>n;
  l=n;
  int b[1000]={};

  if(judge(n)){cout<<l<<": "<<n<<endl;}

  else{int count=0;
  for(int m=2;m<=n;){
    if(n==1){break;}
    if(n%m==0 && judge(m)){n=n/m; b[count]=m; count++; continue;}
    m++;
  }


  cout<<l<<":";
  for(int i=0;;i++){
    if(b[i]==0){cout<<endl; break;}
    cout<<" "<<b[i];
  }}

 
  return 0;
}

