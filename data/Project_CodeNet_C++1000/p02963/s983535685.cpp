#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    ll s;
    cin >> s;
    cout << 0 << " " << 0 << " ";
    ll x2, y2 = 0, x3 = 0, y3;
    x2 = sqrt(s);
    while (x2 * x2 < s) x2++;
    y3 = x2;
    ll a = x2 * y3 - s;
    for (ll i = 1; i * i <= a; i++){
        if (a % i == 0){
            x3 = i;
            y2 = a / i;
            break ;
        }
    }
    cout << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}