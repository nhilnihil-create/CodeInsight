#include<bits/stdc++.h>
using namespace std;

#define INT_BITS 64
typedef long long ll;

ll maxSubarrayXOR(ll a[], int n) {
    int index = 0;
    for(int i = INT_BITS-1; i >= 0; i--) {
        int pos = index;
        int f = 0;
        for(int j = index; j < n; j++) {
            if((a[j] & (1LL << i))) f = 1, pos = j;
        }
        if(!f) continue;
        swap(a[index], a[pos]);
        for(int j = 0; j < n; j++) {
            if(j != index && (a[j] & (1LL << i))) a[j] ^= a[index];
        }
        index++;
    }
    ll res = 0;
    for(int i = 0; i < n; i++) res ^= a[i];
    return res;
}

int n;
ll a[100010], d[60], ans = 0;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        for(int j = 0; j < INT_BITS; j++) {
            if((a[i] & (1LL << j))) d[j]++;
        }
    }
    for(int i = 0; i < 60; i++) {
        if((d[i] & 1)) {
            ans += (1LL << i);
            for(int j = 0; j < n; j++) {
                if((a[j] & (1LL << i))) a[j] ^= (1LL << i);
            }
        }
    }
    cout << ans + 2*maxSubarrayXOR(a, n);
}