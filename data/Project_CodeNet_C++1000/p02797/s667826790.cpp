#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k,s;
    cin >> n >> k >> s;
    int inf;
    if(s==1000000000) inf = s-1;
    else inf = 1000000000;
    for(int i = 0; i < n; i++) {
        if(i<k) cout << s << ' ';
        else if(i<n-1) cout << inf << ' ';
        else cout << inf <<endl;
    }

    return 0;
}