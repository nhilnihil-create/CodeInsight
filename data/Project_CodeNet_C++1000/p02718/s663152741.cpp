#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m;
  cin >>n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  double criteria =0;
  int s = 0;
  rep(i,n) s+= a[i];
  criteria=s/(4*m*1.0);
  if(criteria<=a[n-m]){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}