#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    int n, ans;
    cin >> n;
    vector<int> a(n,0), b(n,0);
    rep(i,n) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n % 2 > 0){
        int m = (n - 1) / 2;
        ans = b[m] - a[m] + 1;
    } else {
        int m = n / 2;
        ans = b[m] + b[m - 1] - a[m] - a[m - 1]+ 1;
    }
    
    cout << ans << "\n";

    return 0;
}

