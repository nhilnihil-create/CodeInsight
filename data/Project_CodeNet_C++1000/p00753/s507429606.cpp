#include <bits/stdc++.h>
using namespace std;

int prime[300000];
bool is_prime[300010];

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

signed main(){
    sieve(300000);
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        int ans = 0;
        for(int i = n + 1; i <= 2 * n; i++){
            if(is_prime[i] == true) ans++;
        }
        cout << ans << endl;
    }
}