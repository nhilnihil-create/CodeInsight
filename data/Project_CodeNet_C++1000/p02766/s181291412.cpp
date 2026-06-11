#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> vec(0);
  while(N>=K) {
vec.push_back(N%K);
    N/=K;
  }
  vec.push_back(N);
 cout<<vec.size()<<endl;
}
  
  
  
  
  

  
