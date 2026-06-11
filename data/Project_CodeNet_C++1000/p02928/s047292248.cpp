#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

long long PRIME = 1e9 + 7;
using namespace std;

long long inv2(){
    long long b = PRIME, u = 1, v = 0;
    long long a = 2;

    while(b){
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }

    u %= PRIME;
    if(u < 0)u += PRIME;
    return u;
}


int main(){
    int N, K;

    cin >> N >> K;
    vector<int> As(N);

    for(int i = 0; i < N; ++i){
        cin >> As.at(i);
    }

    long long num_l, num_r;
    long long ret = 0;

    long long inv_2 = inv2();

    long long coeff_r = ((K + 1) * ((K * inv_2) % PRIME)) % PRIME;
    long long coeff_l = ((K - 1) * ((K * inv_2) % PRIME)) % PRIME;

    for(int i = 0; i < N; ++i){
        int right = 0;
        int left = 0;

        for(int j = 0; j <= i - 1; ++j){
            if(As[i] > As[j]){
                ++left;
            }
        }
        for(int j = i + 1; j < N; ++j){
            if(As[i] > As[j]){
                ++right;
            }
        }

        num_r = (coeff_r * right) % PRIME;
        num_l = (coeff_l * left) % PRIME;

        ret += (num_r + num_l) % PRIME;
        ret %= PRIME;
    }

    cout << ret % PRIME;
}

