#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;


int main() {
    int A, B;
    cin >> A >> B;
    xrep(i, 1, 10000) {
        if((int)(i*0.08)==A && (int)(i*0.1)==B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;



    return 0;
}