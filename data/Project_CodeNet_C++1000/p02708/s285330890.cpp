#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n,k; cin >> n >> k;
    ll s[n+1];
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + i;
    }

    ll ans = 0;
    for(int i = 0; k+i < n+1 ; i++){
        ans = (ans + (s[n]-s[n-(k+i)] - s[k-1+i] + 1 ) ) % mod;
    }
    ans ++;
    cout << ans % mod << endl;
    return 0;
}