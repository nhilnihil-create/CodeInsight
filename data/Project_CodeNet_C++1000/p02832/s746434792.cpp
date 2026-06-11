#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
        a.at(i)--;
    }
    
    int cnt = 0;
    int keep = -1;
    for(auto i: a) {
        if(i != keep + 1) continue;
        else {
            cnt++;
            keep = i;
        }
    }
    int ans = n - cnt;
    if(ans == n) cout << -1 << endl;
    else cout << ans << endl;
}
