#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  int ans=0;
  int a[100];
  for(int i=0;i<n-1;i++){
    cin>>a[i];
    if(i==0){
      ans+=a[i];
    }else{
      ans+=min(a[i-1],a[i]);
    }
  }
  cout<<ans+a[n-2]<<endl;
}
