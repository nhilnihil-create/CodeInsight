#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,l,a[1000];
  cin>>n>>l;
  for(int i=1;i<=n;i++){
    a[i]=l+i-1;
  }
  int nu=0;
  for(int i=1;i<=n;i++){
    nu+=a[i];
  }
  int ma=100000000;
  for(int i=1;i<=n;i++){
    int t=nu-a[i];
    if(abs(t-nu)<abs(ma-nu)){
      ma=t;
    }
  }
  cout<<ma<<endl;
}
       
     
       
       
       
 
