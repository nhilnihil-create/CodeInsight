#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

const int MAX_N = 123459 * 2;

int prime[MAX_N];
bool is_prime[MAX_N + 1];
void sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2*i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

int sum[MAX_N + 10];

int main(){
    int n;
    sieve(MAX_N);
    rep(i, 1, MAX_N){
        sum[i] = sum[i - 1] + is_prime[i];
    }
    while(cin >> n, n){
        int ans = sum[2 * n] - sum[n];
        cout << ans << endl;
    }
}