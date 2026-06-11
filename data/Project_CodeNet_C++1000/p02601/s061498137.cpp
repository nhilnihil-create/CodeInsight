#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B,C,K; cin >> A >> B >> C >> K;
    string ans = "No";
    for (int i=0; i<=K; ++i){
        int r = A, g = B, b = C;
        for (int b=0; b<i; ++b) g *= 2;
        for (int c=0; c<(K-i);++c) b *= 2;
        if (r<g && g<b) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}