#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n;
    cin >> n;
    ll count = 0, i=1;
    ll z = 0;
    while(n>0){
        if(z==0){
            count = 1;
            z++;
            n = n/2;
            continue;
        }

        i *= 2;
        count += i;
        n = n/2;
        z++;
    }
    cout << count;
    return 0;
}
