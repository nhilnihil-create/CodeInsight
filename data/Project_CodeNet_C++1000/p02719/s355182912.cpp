#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
    ll N, K;
    cin >> N >> K;
    N = N % K;
    bool check = true;
    while(check){
        if(abs(N-K)<N){
          N = abs(N - K);
        }
        else
          check = false;
    }
    cout << N << endl;
    return 0;
}