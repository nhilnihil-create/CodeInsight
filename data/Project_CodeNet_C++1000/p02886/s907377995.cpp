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
    int n;
    cin >> n;
    vector<int> takoyaki(n,0);
    repi(i,n,0){
        cin >> takoyaki[i];
    }
    ll ans = 0;
    repi(i,n,0){
        repi(j,n,i + 1){
            ans += takoyaki[i] * takoyaki[j];
        }
    }
    cout << ans << endl;
    return 0;
}
