#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll k;
    cin >> k;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll cou = 0;
    ll q = 10e8 + 7;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                cou++;
            }
        }
    }

    ll ans = 0;
    ans = cou * k;
    ans %= q;
    ll t = k * (k - 1);
    t /= 2;
    t %= q;
    for(int i = 0; i < n; i++){
        cou = 0;
        for(int j = 0; j < n; j++){
            if(i != j){
                if(a[i] > a[j]){
                    cou++;
                }
            }
        }
        ans += cou * t;
        ans %= q;
    }

    cout << ans << endl;
}