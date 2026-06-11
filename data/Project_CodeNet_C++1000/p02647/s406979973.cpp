#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,K; cin >> N >> K;
  vector<int> A(N, 0);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }


  for(int i = 0; i < K; i++){
    vector<int> B(N+1, 0);
    for(int j = 0; j < N; j++){
      int tmp = A[j];
      int left = max(0, j - tmp);
      int right = min(N, j + tmp + 1);
      // j - tmp ~ j + tmp までが+1
      B[left] += 1;
      B[right] -= 1;
    }
    for(int j = 1; j < N; j++){
      B[j] = B[j-1] + B[j];
    }

    int flg = true;
    for(int j = 0; j < N; j++){
      A[j] = B[j];
      if(A[j] < N){
        flg = false;
      }
    }
    if(flg) break;
  }

  for(int j = 0; j < N; j++){
    if(j == N-1) {
      cout << A[j] << endl;
    } else {
      cout << A[j] << " ";
    }
  }



}
