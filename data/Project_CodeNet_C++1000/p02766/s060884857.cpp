#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int ans=0;
    while(n) {
        ++ans;
        n/=k;
    }
    cout << ans;	
    return 0;
} 
 
