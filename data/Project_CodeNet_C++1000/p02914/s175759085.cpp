#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    uint64_t a[100'000], b[100'000];
    uint64_t x = 0;
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i) x ^= a[i];
    for(int i=0;i<n;++i) b[i] = a[i] & (~x);

    int st = 0;
    for(int i=59;i>=0;--i){
        for(int j=st;j<n;++j){
            if((b[j]>>i) & 1){
                swap(b[st], b[j]);
                break;
            }
        }
        if(((b[st]>>i) & 1) == 0) continue;
        for(int j=0;j<n;++j){
            if(j==st) continue;
            if((b[j]>>i) & 1) b[j] ^= b[st];
        }
        ++st;
    }
    uint64_t p = 0;
    for(int i=0;i<n;++i){
        p = max(p, p^b[i]);
    }
    cout << x + 2*p << endl;

    return 0;
}
