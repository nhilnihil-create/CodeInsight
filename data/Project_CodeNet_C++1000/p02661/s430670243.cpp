#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  for(int i=0;i<n;++i){
    cin >> a[i] >> b[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(n%2==0){
    ll mi=a[n/2-1]+a[n/2];
    ll ma=b[n/2-1]+b[n/2];
    cout << ma-mi+1 << endl;
  }else{
    ll mi=a[n/2];
    ll ma=b[n/2];
    cout << ma-mi+1 << endl;
  }
  return 0;
}
