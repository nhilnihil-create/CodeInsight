#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n, ans=0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n-1);
    rep(i, n-1) cin >> b[i];
    rep(i, n-1){
        if(i == 0){
            a[i] = b[i];
            a[i+1] = b[i];
        }
        if(a[i] > b[i]) a[i] = b[i];
        a[i+1] = b[i];
    }
    rep(i,n) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}