#include <bits/stdc++.h>
using namespace std;

void print(vector<int> x){
  int n;
  for (n = 1; n < x.size()-1; n++){
    cout << x.at(n) << " ";
  }
  cout << x.at(n) << endl;
}

void clean(vector<int> &x){
  for (int n = 0; n < x.size(); n++){
    x.at(n) = 0;
  }
}

int main(){
  int N, K;
  cin >> N >> K;

  vector<int> A(N+1);
  vector<int> B(N+1);

  for (int n = 1; n <= N; n++){
    cin >> A.at(n);
  }

  //print(A);

  for (int k = 0; k < K; k++){
    bool is_satu = true;
    clean(B);
    for (int n = 1; n <= N; n++){
      int v = A.at(n);
      int spos = max(1, n-v);
      int epos = min(N, n+v);
      //cout << v << " " << spos << " " << epos << endl;
      B.at(spos)++;
      if (epos+1 <= N){
	B.at(epos+1)--;
      }
    }
    //print(B);
    for (int n = 1; n <= N; n++){
      B.at(n) += B.at(n-1);
      if (B.at(n) != N){
	is_satu = false;
      }
    }
    A = B;
    if (is_satu){
      break;
    }
  }
  print(A);
}
