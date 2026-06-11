#include<iostream>
#include<cmath>
using namespace std;
using ll=long long;
int main(){
ll n,d;
  cin>>n>>d;
  ll a[n]={},b[n]={},ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
    if(sqrt(pow(a[i],2)+pow(b[i],2))<=d) ans++;
  }
  cout<<ans<<endl;
  return 0;
}