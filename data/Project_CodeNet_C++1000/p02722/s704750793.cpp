#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define print(n) cout << n << "\n"

int main(){
    ll n;
    cin >> n;

    ll k = 2, nn;
    unordered_set<ll> ans={n};
    if(n>2) ans.insert(n-1);
    while(k*k<=n){
        if(n % k == 0){
            nn = n;
            while(nn % k == 0) nn /= k;
            if(nn % k == 1) ans.insert(k);
        }
        if(n % k == 1){
            ans.insert(k);
            ans.insert((n-1)/k);
        }
        k++;
    }
    
    print(ans.size());
    return 0;
}