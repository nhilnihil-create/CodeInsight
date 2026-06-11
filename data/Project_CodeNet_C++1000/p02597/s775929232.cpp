#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;  

int main(void){
  long res=0;
  long i,j,k;
  string tmp;
  long n,d;
  
  cin>>n;
  cin>>tmp;
  long r[n];
  
  if(tmp[0]=='R'){
    r[0]=1;
  }
  else{
    r[0]=0;
  }
  for(i=1;i<n;i++){
    if(tmp[i]=='R'){
      r[i]=r[i-1]+1;
    }
    else{
      r[i]=r[i-1];
    }
  }
  res=r[n-1]-r[r[n-1]-1];

  cout<<res<<endl;
  return 0;
}