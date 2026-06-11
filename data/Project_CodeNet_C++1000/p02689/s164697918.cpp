#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N), A(M), B(M);
    for (int i = 0; i < N; i++) cin >> H[i];
    vector<bool> tmp(N);
    for (int i = 0; i < N; i++) tmp[i] = true;
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < M; i++){
        if(H[A[i]-1]>H[B[i]-1]){
          tmp[B[i] - 1] = false;
        } else if (H[B[i] - 1] > H[A[i] - 1]) {
          tmp[A[i] - 1]=false;
        }else if(H[B[i]-1]==H[A[i]-1]){
          tmp[A[i] - 1] = false;
          tmp[B[i] - 1] = false;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
      if (tmp[i] == true) cnt++;
    }
    cout << cnt<< endl;
    return 0;
}