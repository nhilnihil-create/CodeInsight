#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,x;
  cin >> n >> x;
  ll l[n];
  for(int i=0;i<n;i++)cin >> l[i];

  ll s=0;
  ll c=1;
  for(int i=0;i<n;i++){
    if(s+l[i]<=x){
      c++;
      s+=l[i];
    }
    else break;
  }
  cout << c << endl;


}