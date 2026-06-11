#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long int;

ll mygcd(ll a, ll b){
    if(a < b){
        ll tmp = a;
        a = b;
        b = tmp;
    }

    while(b > 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll gcdab = mygcd(a, b);
    cout << gcdab * (a/gcdab) * (b/gcdab) << endl;
    return 0;
}