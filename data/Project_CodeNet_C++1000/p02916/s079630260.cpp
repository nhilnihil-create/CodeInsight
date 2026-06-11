//MISHON69
//DATE:6/22/2020
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[20],b[20],c[19];
  for(int i=0;i<n;i++){
     cin>>a[i];
  }
  for(int i=0;i<n;i++){
     cin>>b[i];
  }
  for(int i=0;i<n-1;i++){
    cin>>c[i];
  }
  int sum=0;
  for(int i=0;i<n;i++){
     int temp1=a[i]-1;
      int temp2=a[i]-2;
     if(i==0){
        sum+=b[temp1];
     }
     else if(a[i]==a[i-1]+1){
        sum+=b[temp1]+c[temp2];
     }
     else
    sum+=b[temp1];
     
  }
  cout<<sum<<endl;

}  
