#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  int ans = 0, suma = 0;
  int a[n];
  rep(i,n){
    cin >> a[i];
    suma += a[i];
  }
  rep(i,n){
    if(a[i]>=(double)suma*1.0/(double)(4*m))ans++;
  }
  if(ans>=m)cout << "Yes\n";
  else cout << "No\n";
  return 0;
}