#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= n; i++)
typedef long long ll;
int main() {
    int n; cin >> n;
    int count = 0;
    rep(i, n){
        if(0 < i && i < 10) count++;
        if(99 < i && i < 1000) count++;
        if(9999 < i && i < 100000) count++;
    }
    cout << count << endl;
    return 0;
}