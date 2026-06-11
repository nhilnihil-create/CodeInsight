#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  double a[n];
  for(int i=0;i<n;i++)cin >> a[i];

  double s=0;
  for(int i=0;i<n;i++)s+=1/a[i];
  s=1/s;

  printf("%.12f",s);

}