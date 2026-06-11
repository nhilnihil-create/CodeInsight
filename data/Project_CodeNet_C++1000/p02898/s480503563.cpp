#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N ,ans = 0 , K;
  cin >> N >> K ;
  vector<int> h(N);
  for(long long int i = 0; i < N; i++) cin >> h[i];
  for(long long int i = 0; i < N; i++)
    if(h[i] >= K) ans++;
  cout << ans << endl;
}
