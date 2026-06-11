#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)

#include <string>
#include <vector>
#include <algorithm>
int main(){
    int n,k; cin >> n >> k;
    int ans = 0,high;
    rep(i,n) {
        cin >> high;
        if (k <= high) ans++;
    }
    cout << ans << endl;
}