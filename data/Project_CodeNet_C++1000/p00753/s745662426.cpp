#include<bits/stdc++.h>
using namespace std;

bool judge(int s){
  if(s==2||s==3){return true;}
  else{
    for(int i=2;i*i<=s;i++){
      if(s%i!=0 && (i+1)*(i+1)>s){return true;}
      if(s%i==0){return false; break;}
  }}
}


int main(){
  while(1){
    int n,count=0;
    cin>>n;
    if(n==0){break;}
    for(int k=n+1;k<=2*n;k++){
      if(judge(k)){count++;}
    }
    cout<<count<<endl;
  }

  
  return 0;
}

