#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


int n;
int a[10000001];


void solve(){
    cin >> n;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = i; j < n+1; j+=i)
        {
            a[j]++;
        }
        
    }
    
    for (int i = 1; i < n+1; i++)
    {
        ans += (ll)a[i]*(ll)i;
    }
    

    cout << ans << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}