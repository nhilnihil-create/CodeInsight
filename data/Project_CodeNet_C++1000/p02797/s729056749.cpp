#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,k,s;
  cin>>n>>k>>s;
  if(n==k){
    for(int i=0;i<n;i++) cout<<s<<" ";
    cout<<endl;
  }
  else{
    if(s==1){
      for(int i=0;i<k;i++){
        cout<<1;
        if(i!=n-1) cout<<" ";
        else cout<<endl;
      }
      for(int i=k;i<n;i++){
        cout<<s+1;
      	if(i!=n-1) cout<<" ";
      	else {cout<<endl; return 0;}
      }
    }
    else{
      for(int i=0;i<k+1;i++){
        if(i%2==0) cout<<s/2;
        else cout<<(s+1)/2;
        if(i!=n-1) cout<<" ";
        else cout<<endl;
      }
    }
    if(s==1e9){
      for(int i=k+1;i<n;i++){
        cout<<1;
        if(i!=n-1) cout<<" ";
        else cout<<endl;
      }
    }
    else{
      for(int i=k+1;i<n;i++){
        cout<<s+1;
      	if(i!=n-1) cout<<" ";
      	else cout<<endl;
      }
    }
  }
}
    
      