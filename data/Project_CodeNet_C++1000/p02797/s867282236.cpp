#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N, K, S;
    cin >> N >> K >> S;
    vector<ll> A(N);

    if(S != 1e9){
        for(int i = 0; i < N; i++){
            A[i] = S + 1;
        }
    }else{
        for(int i = 0; i < N; i++){
            A[i] = S - 1;
        }
    }
    

    for(ll i = 0; i < K; i++){
        A[i] = S;
    }

    for(ll i = 0; i < N; i++){
        cout << A[i] << " ";
    }
}   
