#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N ,ans = 0 ;
  string S ;
  cin >> N ;
  vector<int> d(N);
  for(int i = 0; i < N; i++) cin >> d[i];
  for(int i = 1; i < N; i++)
    for(int j = 0; j < i; j++)
      ans += d[i] * d[j];
  cout << ans << endl;
}
