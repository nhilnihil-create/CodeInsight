#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

ll a,n;

ll tresh = 1000000000000000000;

void solve(){

    cin >> n;

    ll ans = 1;
    bool flag = false; 
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if(a <= tresh/ans){
            ans = ans * a;
        }
        else{
            flag = 1;
        }
        if(a == 0){
            cout << "0" << endl;
            return;
        }
        

    }
    if(flag ){
        cout << -1 << endl;
    }
    else  cout << ans << endl;
    
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}