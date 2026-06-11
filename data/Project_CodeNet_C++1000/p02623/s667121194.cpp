#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,m,k;
  cin >> n >> m >> k;
  vector<long long> a(n+1),b(m+1);
  for(int i=0;i<n;i++) {
    cin >> a[i+1];
    a[i+1]+=a[i];
  }
  for(int i=0;i<m;i++) {
    cin >> b[i+1];
    b[i+1]+=b[i];
  }
  int ok=0,ng=n+m+1;
  while(ok+1<ng) {
    int mid=(ng+ok)>>1;
    long long v=__INT64_MAX__;
    for(int i=max(0,mid-m);i<=min(n,mid);i++) {
      v=min(v,a[i]+b[mid-i]);
    }
    if(v<=k) ok=mid;
    else ng=mid;
  }
  cout << ok << endl;
}