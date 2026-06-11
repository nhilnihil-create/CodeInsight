#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;


#define rep(i,n) for (int i=0; i<(n); i++)
const int INF =2*1e5+5;
const ll BIG = 1e9+7;
const double PI = 3.141592653589793;

P f(int x){
    int a = x%10;
    int b = 0;
    while(x){
        b = x;
        x /= 10;
    }
    return P(a,b);
}


int main(){
    int n;
    cin >> n;
    map<P,int> freq;
    for(int i=1; i<=n; i++){
        P p = f(i);
        freq[p]++;
    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        P p = f(i);
        P q(p.second, p.first);
        ans += freq[q];
    }
    cout << ans << endl;
    return 0;
}