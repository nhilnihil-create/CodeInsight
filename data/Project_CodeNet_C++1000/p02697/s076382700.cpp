/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.19 01:45:50
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n,m;cin >> n >> m;
    int now_l = 1, now_r = n;
    vector<bool> used(n,false);
    while(m > 0) {
        int d = now_r - now_l;
        if (used[d] || used[n-d]) {
            now_r--;
            continue;
        }
        if (2 * d == n) {
            now_r--;
            continue;
        }
        used[d] = true;
        cout << now_l << " " << now_r << endl;
        m--;
        now_r--;
        now_l++;
    }
    
    return 0;
}