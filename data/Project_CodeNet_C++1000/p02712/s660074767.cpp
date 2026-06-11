#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n;cin >> n;
    ll ans=0;
    for(int i = 1; i <= n; i++) {
        if(i % 3 != 0 && i % 5 != 0){
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}