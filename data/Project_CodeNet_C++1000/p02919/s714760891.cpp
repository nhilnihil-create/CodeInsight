//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <set>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  ll N; cin >> N;
  vector <ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  
  vector <ll> loc(N + 1);
  for (int i = 0; i < N; i++) loc[A[i]] = i + 1;
  
  multiset <ll> st{0, 0, N + 1, N + 1};

  ll ans = 0;
  for (ll i = N; i >= 1; i--){
    ll cnt = 0;
    st.insert(loc[i]);
    auto itr = st.find(loc[i]); itr--; itr--;
    
    vector <ll> here(5);
    for (int j = 0; j < 5; j++){
      here[j] = *itr;
      itr++;
    }
    
    cnt += (here[1] - here[0]) * (here[3] - here[2]);
    cnt += (here[4] - here[3]) * (here[2] - here[1]);
    
    ans += cnt * i;
  }
  cout << ans << endl;

  return 0;
}
