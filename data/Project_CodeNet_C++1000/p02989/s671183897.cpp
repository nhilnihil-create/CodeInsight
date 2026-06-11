#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;

int main(){

  ll n;
  cin >> n;
  ll d[n];
  for(int i=0;i<n;i++)cin >> d[i];

  sort(d,d+n);
  if(n%2==1)cout << 0 << endl;
  else{
    cout << d[n/2]-d[n/2-1] << endl;
  }


}