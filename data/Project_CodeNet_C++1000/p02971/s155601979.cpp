#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> A;

int main(){
    cin >> N;
    A.resize(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll M_1 = 0, M_2 = 0;
    ll M_1idx = 0, M_2idx = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] > M_1) {
        M_1 = A[i];
        M_1idx = i;
      }
    }
    for(int i = 0; i < N; i++){
        if(A[i] > M_2 && i!=M_1idx){
            M_2 = A[i];
            M_2idx = i;
        }
    }
    for(int i = 0; i < N; i++){
        if(i!=M_1idx){
            cout <<M_1 << endl;
        }
        else
          cout << M_2 << endl;
    }
    return 0;
}