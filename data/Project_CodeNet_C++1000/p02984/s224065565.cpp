#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    ll x = 0,n;
    cin >> n;
    vector<ll> a(n);
    repi(i,n,0){
        cin >> a[i];
        if(n%2){
            x += i%2 * - 2 * a[i] + a[i];
        }else{
            x += (i+1)%2 * -2 * a[i] + a[i];
        }
    }
    cout << x << " ";
    repi(i,n - 1,0){
        x = 2 * a[i] - x;
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}