#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define inf 1000000000
typedef long long ll;

int main(){
    ll ans =1;
    int x;
    cin >> x;

    ll a=7;

    for(int i=1;i<=x;i++){ 
        if(a%x==0){ 
            cout << ans << endl;

            return 0;
        }
        ans++;
        a=(a*10+7)%x;

    }
    cout << -1 << endl;

    return 0;
}