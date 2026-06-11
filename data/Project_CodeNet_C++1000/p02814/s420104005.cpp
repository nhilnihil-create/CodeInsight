#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,m,i;
  cin >> n >> m;
  vector<ll> a(n),b(n),p(n,0);
  for(i=0;i<n;i++){
    cin >> a.at(i);
    a.at(i) /= 2;
    b.at(i)=a.at(i);
    while(b.at(i)%2==0){
      b.at(i) /= 2;
      p.at(i)++;
    }
    if(p.at(i)!=p.at(0)){
      cout << 0 << endl;
      return 0;
    }
  }
  
  ll lcm=a.at(0);
  for(i=1;i<n;i++){
    lcm=lcm*a.at(i)/__gcd(lcm,a.at(i));
    if(lcm>m){
      cout << 0 << endl;
      return 0;
    }
  }
  
  cout << (m+lcm)/(2*lcm) << endl;
}