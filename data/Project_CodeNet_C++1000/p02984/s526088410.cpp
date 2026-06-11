#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >>n ;
  ll a[n+1];
  for(int i=1;i<n+1;i++){
    cin >> a[i];
    a[i];
  }

  ll b=0;
  for(int i=0;i<n;i++)b+=a[i+1];
  b/=2;
  ll c=b;
  for(int i=1;2*i<=n;i++)b-=a[2*i];
  for(int i=1;2*i+1<=n;i++)c-=a[2*i+1];
  cout << 2*b << endl;
  cout << 2*c << endl;


  for(int i=3;i<n+1;i++){
    if(i%2==1){
      b+=a[i-1];
      b-=a[i-2];
      cout << 2*b << endl;
    }
    else{
      c+=a[i-1];
      c-=a[i-2];
      cout << 2*c << endl;
    }
  }

}