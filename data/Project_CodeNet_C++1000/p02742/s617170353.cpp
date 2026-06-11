#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=61
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  ll h,w;cin>>h>>w;
  if(h==1||w==1){cout<<1<<endl;
  return 0;}
  cout<<h*w/2+(h*w)%2<<endl;
}
