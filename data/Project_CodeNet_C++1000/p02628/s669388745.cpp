#include <iostream>
using namespace std;

int main(){
  int n,k,x;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i]<a[j]){
            x=a[i];
            a[i]=a[j];
            a[j]=x;
        }
    }
  }
  
  x=0;
  for(int i=0;i<k;i++){
    x+=a[i];
  }
  cout<<x;
}
