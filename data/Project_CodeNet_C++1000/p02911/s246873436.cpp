#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n,k,q;
    cin >> n >> k >> q;
    vector<ll> array(n,k);
    vector<ll> seikai(n,0);
    for(int i=0;i<q;i++){
        int a;
        cin >> a;
        seikai.at(a-1) += 1;
    }
    for(int i=0;i<n;i++){
        array.at(i) = array.at(i) + seikai.at(i) - q;
    }

    for(int i=0;i<n;i++){
        if(array.at(i) <= 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}