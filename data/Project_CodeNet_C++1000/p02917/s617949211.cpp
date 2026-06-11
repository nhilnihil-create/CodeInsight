#include <bits/stdc++.h>
using namespace std;

#define rep(i,n)	for(int i=0;i<n;i++)

int main(){
  int n;	cin >>n;
  vector<int>	b(n+1);
  rep(i,n-1)	cin >> b[i];
  b[n-1]=b[n-2];
  
  vector<int>	a(n);
  a[0]=b[0];
  for(int i=1;i<n;i++){
    a[i]=min(b[i-1],b[i]);
  }
  int sum=0;
  rep(i,n)	sum+=a[i];
  cout << sum;
}