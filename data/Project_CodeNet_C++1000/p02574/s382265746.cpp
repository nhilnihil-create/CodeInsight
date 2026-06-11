#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 5;
int N, A[maxn], f[maxn];
vector<int> primes;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void seive() {
    vector<bool> vis(maxn, false);
    for(int i = 2; i < maxn; ++i) {
        if(vis[i] == true) continue;
        for(int j = i; i * j < maxn; ++j) // i * j溢出 
            vis[i * j] = true, f[i * j] = i;
    }
    for(int i = 2; i < maxn; ++i)
        if(vis[i] == false) primes.push_back(i);
}
int main() {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    seive();
    bool pairPirme = true;
    set<int> visFac;
    for(int i = 0; i < N; ++i) {
        int t = A[i];
        for(int i = 2; i <= sqrt(t); ++i) {
            if(t % i == 0) {
                if(visFac.count(i)) {
                    pairPirme = false;
                    break;
                }
                visFac.insert(i);
                while(t % i == 0) t /= i;
            }

        }
        if(t > 1) {
            if(visFac.count(t)) pairPirme = false;
            visFac.insert(t);
        }
    }
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