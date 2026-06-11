#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 444444;

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

int sum[444444];

signed main(){
    sieve(444444);
    rep(i, 1, 444444){
        sum[i] = sum[i - 1];
        if(is_prime[i]) sum[i]++;
    }
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        cout << sum[2 * n] - sum[n] << endl;
    }
}