#include<bits/stdc++.h>

using namespace std;

int main(){
  long long N, K;
  cin >> N >> K;
  
  vector<long long> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  
  vector<long long> s(N + 1);
  s[0] = 0;
  for(int i = 1; i <= N; i++) s[i] = (s[i - 1] + A[i - 1]) % K;
  for(int i = 0; i <= N; i++) s[i] = (s[i] + N * K - i) % K;
  
  unordered_map<long long, long long> m;
  for(int j = 0; j <= min(K - 1, N); j++) m[s[j]]++;
  
  long long cnt = 0;
  for(int i = 0; i < N; i++){
    m[s[i]]--;
    cnt += m[s[i]];
    if(i + K <= N) m[s[i + K]]++;
  }
  
  cout << cnt << endl;
  
  return 0;
}