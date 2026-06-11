#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+1),b(n);
    for(ll i=0;i<n+1;i++) cin >> a.at(i);
    for(ll i=0;i<n;i++) cin >> b.at(i);
    ll count = 0;
    for(int i=0;i<n;i++){
        if(a.at(i) > b.at(i)){
            count += b.at(i);
        }else{
            count += a.at(i);
            ll nokori = b.at(i) - a.at(i);
            if(a.at(i+1) < nokori){
                count += a.at(i+1);
                a.at(i+1) = 0;
            }else{
                count += nokori;
                a.at(i+1) -= nokori;
            }
        }
        //cout << count << endl;
    }
    cout << count << endl;
}