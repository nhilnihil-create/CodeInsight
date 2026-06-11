#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long x,k,d; cin >> x >> k >> d;
    long long ax = abs(x);
    long long res = min(k, ax/d);
    long long ns = ax - d*res;
    if((k-res)%2)
        ns -= d;
    cout << abs(ns) << endl;
    return 0;
}