#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  
  int ans=0;
  if(n==2){
      cout<<a[1]-a[0]<<endl;
      cout<<a[1]<<" "<<a[0]<<endl;
  }
  else{
  if(a[0]<=0&&a[n-1]>=0){
    for(int i=0;i<n;i++) ans+=abs(a[i]); 
    cout<<ans<<endl;
    
    for(int i=1;i<n;i++){
      if(i!=n-1){
      if(a[i]>0){
        cout<<a[0]<<" "<<a[i]<<endl;
        a[0]-=a[i];
      }
      else{
        cout<<a[n-1]<<" "<<a[i]<<endl;
        a[n-1]-=a[i];
      }
      }
      else{
        cout<<a[n-1]<<" "<<a[0]<<endl;
      }
    }
    
  }
  else if(a[0]>0){
    for(int i=1;i<n;i++) ans+=a[i];
    cout<<ans-a[0]<<endl;
    
    cout<<a[0]<<" "<<a[n-1]<<endl;
    a[0]-=a[n-1];
    for(int i=1;i<n-2;i++){
      cout<<a[0]<<" "<<a[i]<<endl;
      a[0]-=a[i];
    }
    cout<<a[n-2]<<" "<<a[0]<<endl;
    
  }
  else{
    reverse(a,a+n);
    for(int i=1;i<n;i++) ans-=a[i];
    cout<<ans+a[0]<<endl;
    
    cout<<a[0]<<" "<<a[n-1]<<endl;
    a[0]-=a[n-1];
    for(int i=1;i<n-1;i++){
      cout<<a[0]<<" "<<a[i]<<endl;
      a[0]-=a[i];
    }
    
  }
  }
}
