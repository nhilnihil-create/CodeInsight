#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    while(~scanf("%d",&n)){
        if(n == 0) break;

        int ans = 0;
        for(int i=1; i<=n; i++) {
            int sum = 0;
            for(int j=i; j<=n; j++) {
                if(sum > n) break;
                if(sum == n) ans++;
                sum += j;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}