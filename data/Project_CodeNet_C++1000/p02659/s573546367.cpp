#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

double a,b;


void solve(){

    cin >> a >> b;

    

    ll c = (ll)a * (ll)(b*100+0.1);
    c = c/100;
    cout << c << endl;
}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}