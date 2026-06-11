#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;


int main() {
    int K, X;
    cin >> K >> X;
    int all = K*500;
    if(all>=X) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}