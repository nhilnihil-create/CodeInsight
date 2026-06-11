#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main(){
    ll a,b;
    cin >> a >> b;
    while(a%b != 0){
        ll temp = a%b;
        a = b;
        b = temp;
    }
    ll gcm = b;

    set<ll> s;
    s.insert(1);
    ll n = gcm;
    ll i = 2;
    while(i<sqrt(n)+1){
        if(n%i == 0){
            s.insert(i);
            n /= i;
            i = 1;
        }
        i += 1;
    }

    if(n != 1) s.insert(n);

    cout << s.size()<< endl;
}
