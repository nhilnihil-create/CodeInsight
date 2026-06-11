#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;
    cin >> n;
    ll count = 0, i=1;
    while(n>0){
        i *= 2;
        count += i;
        n = n/2;
    }
    cout << count/2;
    return 0;
}
