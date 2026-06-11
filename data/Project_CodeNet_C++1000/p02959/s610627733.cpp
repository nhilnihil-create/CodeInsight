#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)

int main(){
  int n;	cin >> n;
  vector<long long>	a(n+1);
  vector<long long>	b(n);
  rep(i,n+1)	cin >> a[i];
  rep(i,n)	cin >> b[i];
  
  long long ans=0;
  rep(i,n){
    long long x=min(a[i],b[i]);
    b[i]-=x;
    ans+=x;
    x=min(a[i+1],b[i]);
    a[i+1]-=x;
    ans+=x;
  }
  cout << ans;
}