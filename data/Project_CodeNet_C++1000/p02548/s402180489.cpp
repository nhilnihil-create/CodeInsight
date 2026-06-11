#include<iostream>
using ll=long long;
using namespace std;

int main(){
	int n;
  	cin>>n;
  	ll ans=0;
	for(int a=1;a<=n;a++){
      ans+=(n-1)/a;
    }
  cout<<ans<<endl;
  return 0;
}