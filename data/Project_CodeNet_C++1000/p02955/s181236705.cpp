#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  int sum = 0;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    sum += A[i];
  }
  sort(A.begin(), A.end(), greater<int>());
  
  vector<int> d;
  for(int i = 1; i * i <= sum; i++){
    if(sum % i == 0) {
      d.push_back(i);
      d.push_back(sum / i);
    }
  }
  sort(d.begin(), d.end(), greater<int>());
  
  int max_gcd = 1;
  for(int gcd : d){
    int s = sum;
    priority_queue<int> pq;
    int man = 0;
    for(int i = 0; i < N; i++){
      man += A[i] % gcd;
      s -= (A[i] / gcd) * gcd;
      pq.push(A[i] % gcd);
    }
    
    while(s && !pq.empty()){
      man -= pq.top();
      s -= gcd;
      pq.pop();
    }
    
    if(man <= K){
      max_gcd = gcd;
      break;
    }
  }
  
  cout << max_gcd << endl;
  
  return 0;
}