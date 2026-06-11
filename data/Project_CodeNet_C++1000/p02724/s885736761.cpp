#include <bits/stdc++.h>          
using namespace std;   
typedef long long ll;            

int main() {
    ll X;
    cin >> X;
    ll ans = 0;
    ans = 1000*(X/500) + 5*((X%500)/5);
    cout << ans << endl;
}