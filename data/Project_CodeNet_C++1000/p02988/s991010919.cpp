#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll p[n];
  for(int i=0;i<n;i++)cin >> p[i];

  ll s=0;
  for(int i=1;i<n-1;i++){
    if(max(p[i],max(p[i-1],p[i+1]))!=p[i] && min(p[i],min(p[i-1],p[i+1]))!=p[i])s++;
  }

  cout << s << endl;

}