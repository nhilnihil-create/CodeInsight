 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
   ll n,k;
  cin>>n>>k;
  ll a[k];
  for(ll i=0;i<k;i++){
    cin>>a[i];
  }
  sort(a,a+k);
  for(ll i=k-1;i>=0;i--){
    n = n - a[i];
    
    if(n<=0)
       break;
  }
  
  if(n<=0)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}