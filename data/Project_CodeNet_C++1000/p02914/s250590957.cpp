#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    ll x = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x ^= a[i];
    }
    ll r = 0;
    for(int j = 0; j < 60; j++){
        if((x >> j) & 1){
            r += (1ll << j);
            for(int i = 0; i < n; i++) a[i] &= (1ll << 60) - 1 - (1ll << j);
        }
    }
    ll b[100002] {0};
    for(int i = 0; i < n; i++){
        for(int j = 59; j >= 0; j--) if((a[i] >> j) & 1) a[i] ^= b[j];
        for(int j = 59; j >= 0; j--)
            if((a[i] >> j) & 1){
                b[j] = a[i];
                break;
            }
    }
    for(int j = 0; j < 60; j++){
        for(int k = j + 1; k < 60; k++) if((b[k] >> j) & 1) b[k] ^= b[j];
    }
    ll s = 0;
    for(int j = 0; j < 60; j++) s ^= b[j];
    cout << r + s * 2 << endl;
}