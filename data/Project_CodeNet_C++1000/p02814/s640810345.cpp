#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  ll n,m,L=1;
  cin>>n>>m;
  ll a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    a[i]/=2;
    L=lcm(L,a[i]);
  }
  for(int i=0;i<n;i++) if(L/a[i]%2==0){cout<<0<<endl;return 0;}
  cout<<m/(2*L)+(m%(2*L)>=L ? 1 : 0)<<endl;
}
