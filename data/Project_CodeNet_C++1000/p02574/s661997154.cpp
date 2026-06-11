#include <bits/stdc++.h>
using namespace std;
int ans, a[1000001], n, maxi;
bool dk, check[1000001];
void sieve(){
    a[0] = a[1] = 1;
    for(int i = 2; i * i <= 1000000; i++){
        if(a[i] != 0) continue;
        for(int j = i * i; j <= 1000000; j += i) if(a[j] == 0) a[j] = i;
    }
}
void fact(int x){
    int t = x, pre = 0;
    while(t != 1){
        if(a[t] == 0) a[t] = t; 
        if(check[a[t]] && a[t] != pre) {dk = true; break;}
        else check[a[t]] = true;
        pre = a[t], t /= a[t];
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    sieve();
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ans = i == 0 ? x : __gcd(ans, x);
        if(!dk) fact(x);
    }
    if(dk){
        if(ans == 1) cout << "setwise coprime";
        else cout << "not coprime";
    }
    else cout << "pairwise coprime";
    return 0;
}