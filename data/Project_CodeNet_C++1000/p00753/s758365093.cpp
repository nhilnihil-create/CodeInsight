#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <iomanip>
#include <cassert>
using namespace std;

const int LIM = 300000;

bool isprime[LIM];

void eratosthenes(void){
    for(int i = 0; i < LIM; i++) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for(int i = 2; i * i < LIM; i++){
        if(isprime[i]){
            for(int j = i * i; j < LIM; j += i){
                isprime[j] = false;
            }
        }
    }
}

int main(){
    eratosthenes();
    int N;
    while(true){
        scanf("%d", &N);
        if(N == 0) break;
        int ans = 0;
        for(int i = N + 1; i <= 2 * N; i++){
            if(isprime[i]) ++ ans;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}