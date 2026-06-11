#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int n; ll k; cin >> n >> k;
    int a[n]; inarray(a,n);
    ll ans =0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(a[i] > a[j]){
                if(i < j){
                    ans += k * (k+1)/2;
                    ans %= mod;
                }else{
                    ans += k * (k-1)/2;
                    ans %= mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}