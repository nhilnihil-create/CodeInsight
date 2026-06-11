#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  vector<int> x(n);
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  int a=0;
  int max=x[0];
  for(int i=0;i<n;i++){
    if(max<x[i]){
      max=x[i];
    }
    if(max-1<=x[i]){
      a++;
    }
  }
  if(a==n){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}