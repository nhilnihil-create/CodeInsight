#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int check(int mid,int K,vector<int> &L) {

  int cnt = 0;
  for(int i = 0;i < L.size();i++) {
    double num = (double)L[i]/mid;
    if(mid <= L[i]) cnt += ceil(num) - 1;
  }

  if(cnt <= K) return 1;
  return 0;
}

int main() {
  
  int N,K;
  cin >> N >> K;

  vector<int> L(N);
  for(int i = 0;i < N;i++) cin >> L[i];

  int ng = 0,ok = 1e9+1;
  while(abs(ok-ng) > 1) {
    int mid = (ok+ng)/2;
    if(check(mid,K,L)) {
      ok = mid;
    }else {
      ng = mid;
    }
  }

  cout << ok << endl;
  

}
