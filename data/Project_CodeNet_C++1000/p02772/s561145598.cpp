#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, x; cin >> n; bool ok = 1;
    while(n--) {
        cin >> x;
        if(x % 2 == 0) if(x % 3 && x % 5) ok = 0;
    }    
    cout << (ok ? "APPROVED" : "DENIED");
}