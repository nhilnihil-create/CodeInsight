#include<bits/stdc++.h>
#define ll long long

using namespace std;

long long gcd(long long x, long long y){
    if(y == 0) return x;
    return gcd(y, x % y);
}

int main(void){
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll Cb = 0;
    while(A[0] % 2 == 0){
        Cb++;
        A[0] >>= 1;
    }
    A[0] <<= Cb;
    for(int i = 0; i < N; i++){
        ll Ab = 0;
        while(A[i] % 2 == 0){
            Ab++;
            A[i] >>= 1;
        }
        if(Ab != Cb){
            cout << 0 << endl;
            return 0;
        }
        A[i] <<= Ab;
    }
    ll T = 1;
    for(int i = 0; i < N; i++){
        A[i] >>= 1;
        T = T * A[i] / gcd(T, A[i]);
        // cout << T << endl;
    }

    cout << (M / T + 1) / 2 << endl;    
}
