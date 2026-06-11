#include <bits/stdc++.h>
using namespace std;;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> L(n);
    for (ll i = 0; i < n; i++){
        cin >> L[i];
    }
    sort(L.begin(),L.end());
    reverse(L.begin(),L.end());
    int counter = 0;
    for (ll i = 0; i < n-2; i++){
        for (ll j = i+1; j < n-1; j++){
            for (ll k = j+1; k<n; k++){
                if (L[i] != L[j] && L[i] != L[k] && L[j] != L[k]){
                    if (L[i]-L[j] < L[k]){
                        counter++;
                    }
                }
            }
        }
    }
    cout << counter << endl;
}