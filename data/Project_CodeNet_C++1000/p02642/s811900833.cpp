#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int n, int m){
    if(n < m) swap(n, m);
    if(m == 0) return n;
    else return gcd(m, n%m);
}

int lcm(int n, int m){
    return n/gcd(n, m)*m;
}

int aho(int n, vector<int> a){
    int ans = 0;
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n; j++){
            if(i == j) continue;
            if(a[i] % a[j] == 0) break;
        }
        if(j == n) ans++;
    }
    return ans;
}

int solve(int n, vector<int> a){
    int max = 1000001;
    vector<int> sieve(max, 0);
    for(int i=0; i<n; i++){
        sieve[a[i]]++;
    }

    for(int i=1; i<max; i++){
        if(sieve[i] >= 1){
            for(int j=2*i; j<max; j+=i){
                sieve[j] = -1;
            }
        }
        if(sieve[i] > 1) sieve[i] = -1;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(sieve[a[i]] != -1) ans++;
    }
    return ans;
}

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cout << solve(n, a) << endl;

    return 0;
}