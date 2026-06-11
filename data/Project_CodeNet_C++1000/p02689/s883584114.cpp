#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    ll N, M;
    std::cin >> N >> M;

    std::vector<ll> H(N);
    std::vector<ll> A(M), B(M);
    for(ll i=0; i < N; i++) {
        std::cin >> H[i];
    }
    for(ll i=0; i < M; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<ll> data(N+1, 0);
    for(ll i=0; i < M; i++) {
        if(H[A[i]-1] > H[B[i]-1]) {
            if(data[A[i]] != -1) {
                data[A[i]] = 1;
            }
            data[B[i]] = -1;
        }
        else if(H[A[i]-1] < H[B[i]-1]){
            if(data[B[i]] != -1) {
                data[B[i]] = 1;
            }
            data[A[i]] = -1;
        }
        else {
            data[A[i]] = -1;
            data[B[i]] = -1;
        }
    }

    ll count = 0;
    for(ll i=1; i <= N; i++) {
        if(data[i] != -1) {
            count++;
        }
    }
    std::cout << count << std::endl;
}