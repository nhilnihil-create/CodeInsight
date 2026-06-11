#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

int n,m,a;

void solve(){

    cin >> n >> m;


    int ans = n;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        ans -= a;
        if(ans < 0){
            cout << -1 << endl;
            return;
        }
    }
    
    cout << ans << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}