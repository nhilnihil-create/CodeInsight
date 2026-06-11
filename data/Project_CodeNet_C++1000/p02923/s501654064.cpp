#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll h[n];
  for(int i=0;i<n;i++)cin >> h[i];

  ll m=0;
  for(int i=0;i<n;i++){
    if(h[i]<h[i+1])continue;
    ll k=0;
    while(i+k+1<=n-1 && h[i+k]>=h[i+k+1]){
      k++;
    }
    i+=k;
    m=max(m,k);
  }
  cout << m << endl;

}