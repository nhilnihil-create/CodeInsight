#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n; cin >> n;
    ll d[n], D[n];
    for(int i = 0; i < n; i++) d[i] = 0;
    for(int i = 0; i < n; i++){
        cin >> D[i];
        d[D[i]]++;
    }
    if(D[0] != 0){
        cout << 0 << endl; return 0;
    }
    if(d[0] != 1){
        cout << 0 << endl; return 0;
    }
    ll ans = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < d[i]; j++){
            ans *= d[i-1]; ans %= mod;
        }
    }
    cout << ans << endl;

    return 0;
}
