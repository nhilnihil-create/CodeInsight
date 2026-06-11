#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n]={};
  for(int i=0;i<n;i++) cin>>a[i];
  long long ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        if(i<j&&j<k&&a[i]!=a[j]&&a[j]!=a[k]&&a[k]!=a[i]&&((a[i]+a[j])>a[k]&&(a[j]+a[k])>a[i]&&(a[i]+a[k])>a[j])){
          
            ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}