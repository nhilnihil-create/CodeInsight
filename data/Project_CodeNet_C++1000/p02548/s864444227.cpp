#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for(int i=1; i<n; i++){
        int t = n/i;
        if(n%i==0) t--;
        // cout << i << ' ' << t << "\n";
        ans += t;
    }
    cout << ans;
}