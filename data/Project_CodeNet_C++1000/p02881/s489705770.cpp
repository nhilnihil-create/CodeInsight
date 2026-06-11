#include<iostream>
#include<cmath>
#include<algorithm>
#define Fast ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define loop(i, n) for(i=1; i<=n; i++)
#define ll long long
using namespace std;
int main() {
    Fast;
    ll n;
    cin >> n;
    ll mint = 1000000000002;
    ll i, tmp = 0;
    for(i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            ll x = n/i;
            tmp = i + x - 2;
            mint = min(tmp, mint);
        }
    }
    cout << mint << endl;
    return 0;
}