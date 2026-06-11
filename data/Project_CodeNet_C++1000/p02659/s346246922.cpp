#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    ll x;
    cin >> x;
    double y;
    cin >> y;
    
    ll y1 = 100*y + 0.5;
    x *= y1;
    x = x/100;
    cout << x << endl;
}