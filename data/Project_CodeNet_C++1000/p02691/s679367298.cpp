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
    map<long long,long long > L;
    map<long long,long long> R;
    
    for(int i = 1; i <= N; i++) {
        int H;
        cin >> H;
        L[i+H]++;
        R[i-H]++;
    }
    
    auto it = L.begin();
    long long ans = 0;
    while(it != L.end()) {
        long long X = it->first; 
        ans = ans + (it->second * R[X]);
        it++;
    }
    cout << ans << endl;
}
