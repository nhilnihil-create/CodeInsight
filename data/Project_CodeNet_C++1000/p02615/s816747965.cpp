#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int n, k, tmp;
int a[200000];

vector<int> v;

void solve(){
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = tmp;
    }

    sort(a, a+n, greater<int>());
    
    ll ans = (ll)a[0];
    int j = 1;
    for (int i = 2; i < n; i++)
    {
        ans += (ll)a[j];
        if(i%2) j++;
    }
    
    cout << ans << endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}