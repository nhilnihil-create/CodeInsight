#include<bits//stdc++.h>
using namespace std;
#define rep(i,n) for(int i =0;i<n;i++)
#define ALL(a) a.begin(),a.end()
typedef long long int ll;
int main(){
  int n;cin >>n;vector<ll> x(n),y(n),z(n),w(n);
  rep(i,n) cin >> x[i] >> y[i];
  rep(i,n){
    z[i]=x[i]+y[i];w[i] = x[i]-y[i];
  }sort(ALL(z));sort(ALL(w));
  cout << max(z[n-1]-z[0],w[n-1]-w[0])<<endl;
}