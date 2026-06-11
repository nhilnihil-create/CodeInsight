#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

  int a[n];
  for(int i=1;i<=n;i++){
    a[i]=0;
  }

  int A[n];
  for(int i =2;i<=n;i++){
    cin>>A[i];
    a[A[i]]++;
  }

  for(int i=1;i<=n;i++){
    cout<<a[i]<<endl;
  }

  return 0;
  
}