#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back

using namespace std;

signed main(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1;i<=n;i++){
        for(int z = 1;z<=n;z++){
            for(int j = 1;j<=n;j++){
                res += __gcd(__gcd(i,z),j);
            }
        }
    }
    cout << res;
}
