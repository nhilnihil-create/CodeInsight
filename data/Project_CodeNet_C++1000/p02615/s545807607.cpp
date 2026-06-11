#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  
  ll N,T; 
  cin >> N;
  vector<ll> vec(N);
  for(ll i = 0; i < N; i++){
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end(), greater<ll>());
  T = 0;
  
  for(ll i = 1; i < N; i++){
    T += vec[i/2];
  }
  cout << T << endl; 
  
}
