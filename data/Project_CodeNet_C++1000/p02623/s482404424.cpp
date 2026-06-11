#include <bits/stdc++.h>

using namespace std;
const long long INF = 1LL <<60;

int main(void){
  long long n,m,k;
  long long i,j;
  long long tmp,count=-1;
  long long b=0,c;
  long long res=0;
  
  cin>>n>>m>>k;
  long long a[n]={};

  
  cin>>a[0];
  if(a[0]>k){
    count=0;
    for(i=1;i<n;i++){
      cin>>tmp;
    }
  }
  else{
    for(i=1;i<n;i++){
      cin>>tmp;
      a[i]=a[i-1]+tmp;
      if(a[i]>k){
        count=i;
        break;
      }
    }
  }
  if(i<n-1){
    for(i=i+1;i<n;i++){
      cin>>tmp;
    }
  }
  if(count==-1){
    count=n;
  }
  if(count>0){
    c=a[count-1];
  }
  else{
    c=0;
  }
  //cout<<count<<endl;
  for(i=0;i<m;i++){
    cin>>tmp;
    b=b+tmp;
    //cout<<b<<endl;
    if(b+c>k){
      if(count>1){
        //cout<<b<<" "<<c<<" "<<count<<" "<<i<<endl;
        res=max(count+i,res);
        count--;
        c=a[count-1];
      }
      else if(count==1){
        res=max(count+i,res);
        c=0;
        count=0;
      }
      else{
        //cout<<b<<" "<<count+i<<endl;
        res=max(count+i,res);
        break;
      }
    }
  }    
  if(i==m){
    res=max(count+i,res);
  }
  
  cout<<res<<endl;
  return 0;
  
}