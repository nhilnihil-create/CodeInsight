#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
ll A[100000];
 
int main(){
    int i;
    ll a = 0, b, c, z = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> A[i];
        a ^= A[i];
    }
    for (b = 1LL << 59; b; b >>= 1) {
        if (b & a) continue;
        for (i = 0; i < N; i++) if (A[i] & b) break;
        if (i == N) continue;
        if(!(z & b)) z ^= A[i];
        c = A[i];
        for (; i < N; i++) if (A[i] & b) A[i] ^= c;
    }
    cout << 2 * (z & ~a) + a << endl;
}