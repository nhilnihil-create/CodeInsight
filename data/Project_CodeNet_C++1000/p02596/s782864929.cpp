#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

ll K;

void solve(){

    cin >> K; 

    ll mod = 7;
    int ans = -1;
    for (int i = 1; i < K+1; i++)
    {
        mod = mod % K;
        if(mod == 0){
            ans = i;
            break;
        }
        mod = mod*10+7;
    }
    
    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}