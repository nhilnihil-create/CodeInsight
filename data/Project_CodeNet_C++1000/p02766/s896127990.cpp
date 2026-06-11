#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    int ans = 1;
    while(n / k > 0){
        n /= k;
        ans ++;
    }
    cout << ans << endl;
}