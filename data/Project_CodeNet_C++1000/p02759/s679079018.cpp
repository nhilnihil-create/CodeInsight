#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e9+7;

int main(){
    ll n,p;
    cin >> n;
    if(n % 2 != 0){
        p = n/2 + 1;
        cout << p;
    }else{
        p = n;
        cout << p/2;
    }

}