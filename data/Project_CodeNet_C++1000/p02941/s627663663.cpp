#include<bits/stdc++.h>
using namespace std;
using P = pair<int64_t,int64_t>;
int main(){
  int64_t N;
  cin >> N;
  
  bool flag = true;
  int64_t cnt = 0;
  int64_t t_cnt = 0;
  priority_queue<P> PQ;
  
  vector<int64_t> A(N);
  for(int64_t i=0; i<N; i++){
    cin >> A[i];
  }
  vector<int64_t> B(N);
  for(int64_t i=0; i<N; i++){
    cin >> B[i];
    if(A[i] == B[i]){
      t_cnt++;
    }
    else{
      P add = {B[i],i};
      PQ.push(add);
    }
  }
  
  P d = {0,-1};
  PQ.push(d);
  
  while(PQ.size()){
    P p = PQ.top();
    PQ.pop();
    if(p.second == -1){
      break;
    }
    int64_t a, b, c;
    if(p.second == 0){
      a = B[N-1] + B[1];
      b = p.second;
      c = max({A[b], B[N-1], B[1]});
    }
    else if(p.second == N-1){
      a = B[N-2] + B[0];
      b = p.second;
      c = max({A[b], B[N-2], B[0]});
    }
    else{
      a =  B[p.second + 1] + B[p.second - 1];
      b = p.second;
      c = max({A[b], B[b+1], B[b-1]});
    }
    c = p.first - c;
    int64_t num =  (c+a-1)/a;
    cnt += num;
    if(num == 0){
      break;
    }
    B[p.second] = p.first - a*num;
    if(B[p.second] == A[p.second]){
      t_cnt++;
    }
    else if(B[p.second] < A[p.second]){
      flag = false;
      break;
    }
    else{
      P add = {B[p.second],b};
      PQ.push(add);
    }
  }
  
  if(flag && t_cnt == N){
    cout << cnt << endl;
  }
  else{
    cout << -1 << endl;
  }
}