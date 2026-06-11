#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> w(n); for(int i = 0;i < n; i++) cin >> w[i];
    int ans = 1e9;
    for(int i = 1; i < n; i++){
        int lsum = 0, rsum = 0;
        for(int j = 0; j < n; j++){
            if(j < i) lsum += w[j];
            else rsum += w[j];
        }
        ans = min(ans, abs(rsum-lsum));
    }
    cout << ans << endl;
    return 0;
}