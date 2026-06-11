#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n; cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll l = a[0], r = a[n-1], i = 1, j = n-2;
    while(i <= j){
        if(l < r){l+= a[i]; i++;}
        else if(l == r) {
            if(i != j) {l += a[i]; r += a[j]; i++; j--;}
            else {l += a[i]; i++;}
        }
        else {r += a[j]; j--;}
    }
    cout << abs(l-r) << endl;
    return 0;
}