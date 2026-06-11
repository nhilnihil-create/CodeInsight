#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int N, K, min=1001, sum_price=0;
  cin >> N >> K;
 vector<int> price(N);
  rep(i,N) cin >> price.at(i);
  
  sort(price.begin(), price.end());
   
  rep(i,K) sum_price += price.at(i);
  
  cout << sum_price << endl;
  
}
    
  
  
    
