#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n;
  cin>>n;
  ll a[100005];
  ll ans=1;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==0){
    	cout<<"0"<<endl;
      	return 0;
    }
  }
  for(int i=0;i<n;i++){
    if(a[i]<=1000000000000000000/ans){
      ans*=a[i];
    }
    else{
    	cout<<"-1"<<endl;
      	return 0;
    }
  }
  cout<<ans<<endl;
  return 0;
}

