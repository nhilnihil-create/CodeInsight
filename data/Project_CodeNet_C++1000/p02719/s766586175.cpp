#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    ll n , k;
    cin >> n >> k;

    if(n < k){
        cout << min(n, k-n);
        return 0;
    }
    else{
        if(n%k == 0){
            cout << 0;
            return 0;
        }
        else{
            cout << min(n%k, abs(n%k - k));
            return 0;
        }
    }

    return 0;
}