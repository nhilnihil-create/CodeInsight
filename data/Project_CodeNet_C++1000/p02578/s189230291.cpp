#include<iostream>
using namespace std;
int main(){
int n;
  cin>>n;
  long long a[n];
 for(int i=0;i<n;i++){
   cin>>a[i];
 }
  long long max=0,ans=0;
  for(int i=0;i<n;i++){
    if(max<a[i]){
      max=a[i];
    }
    else ans+=max-a[i];
  }
  cout<<ans<<endl;
  return 0;
}
