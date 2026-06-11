#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 5;
int N, A[maxn], f[maxn];
vector<int> primes;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void seive() {
    vector<bool> vis(maxn, false);
    for(int i = 2; i < maxn; ++i) {
        if(vis[i]) {
            continue;
        }
        for(int j = i; j < maxn / i; ++j) {
            vis[i * j] = true, f[i * j] = i;
        }
    }
    for(int i = 2; i < maxn; ++i)
        if(!vis[i]) primes.push_back(i);
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // Check pairwise coprime.
    seive();
    bool pairPirme = true;
    unordered_set<int> visFac;
    for(int i = 0; i < N; ++i) {
        int t = A[i];
        while(f[t]) {
            int p = f[t];
            while(t % p == 0) t /= p;
            if(visFac.count(p)) pairPirme = false;
            visFac.insert(p);
        }
        if(t > 1) {
            if(visFac.count(t)) pairPirme = false;
            visFac.insert(t);
        }
    }

    // Check setwise coprime.
    int t = A[0];
    for(int i = 1; i < N; ++i) {
        t = gcd(t, A[i]);
    }
    bool setPrime = (t == 1);

    if(pairPirme) cout << "pairwise coprime" << endl;
    else if(setPrime) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}