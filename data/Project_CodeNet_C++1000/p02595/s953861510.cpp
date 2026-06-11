#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  ll D,N,count=0;
  cin >> N >> D;
  cout << endl;
  
  vector<ll> x(N);
  vector<ll> y(N);
  
  
  rep(i,N){
    cin >> x.at(i) >> y.at(i);
    ll a=D*D-x.at(i)*x.at(i)-y.at(i)*y.at(i);
    if(a>=0) count++;
  }
  
  cout << count << endl;

}
  
