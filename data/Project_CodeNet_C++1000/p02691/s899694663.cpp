/**
 * author: dannysmyda
 */ 
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    map<long long,long long> L;
    
    long long ans = 0;
    for(int i = 1; i <= N; i++) {
        int H;
        cin >> H;
        ans += L[i-H];
        L[i+H]++;
    }
    
    cout << ans << endl;
}
