#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,K,C;
  cin >> N >> K >> C;
  string S; cin >> S;

  if(N == 1){
    if(K == 1){
      cout << 1 << endl;
    } else { 
      cout << endl;
    }
    return 0;
  }


  vector<int> left(N,0);
  vector<int> right(N,0);

  for(int i = 0; i < N; i++){
    if(S[i] == 'x'){
      if(i > 0){
        left[i] = left[i-1];
      } else { 
        left[i] = 0;
      }
    }
    if(S[i] == 'o'){
      if(i >= C+1){
        left[i] = left[i-C-1] + 1;
      } else { 
        left[i] = 1;
      }
    }
  }

  for(int i = N-1; i >= 0; i--){
    if(S[i] == 'x'){
      if(i < N-1){
        right[i] = right[i+1];
      } else { 
        right[i] = 0;
      }
    }
    if(S[i] == 'o'){
      if(i + C + 1 < N){
        right[i] = right[i+C+1] + 1;
      } else {
        right[i] = 1;
      }
    }
  }

  int num = 0;
  for(int i = 0; i < N; i++){

    if(i == 0){
      if(right[i+1] < K){
        cout << i + 1 << endl;
        num++;
      }
    }

    if(i == N-1){
      if(left[i-1] < K){
        cout << i + 1 << endl;
        num++;
      }
    }

    if(i > 0 && i < N-1){
      if(left[i-1] + right[i+1] < K){
        cout << i+1 << endl;
        num++;
      }
    }
  }

  if(num == 0){
    cout << endl;
  }
}
