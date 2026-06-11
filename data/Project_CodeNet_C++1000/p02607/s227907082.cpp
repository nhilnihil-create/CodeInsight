#include<iostream>
using namespace std;
int main(){
int n;
  cin>>n;
int   a[n];
  for(int i=0;i<n;i++){
  cin>>a[i];}
  int count =0;
  for(int i=0;i<n;i++){
  if((i+1)%2!=0&&a[i]%2!=0){
  count++;
  }
  }
  cout<<count<<endl;
  
  
}