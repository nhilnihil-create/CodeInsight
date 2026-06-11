#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long mul=1;
  long long a[n];
  long long z = 0;
  for(int i=0;i<n;i++) {
    cin>>a[i];
    if(a[i]==0) z =1;
  }
  if(z==1){
    cout<<0;
    return 0;
  }
  for(int i=0;i<n;i++){
    if(a[i]<=1000000000000000000/mul){
    	mul*=a[i];
    }
    else{
   		cout<<-1;
        return 0;
    }
  	
    
  }
  cout<<mul;
}
    
