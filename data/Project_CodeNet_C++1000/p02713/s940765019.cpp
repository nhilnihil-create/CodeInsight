#include<bits/stdc++.h>
#define rep(i,n) for (int i=1; i<=n; i++)
using namespace std;
int main(){
    int K;
    cin >> K;
    int sum = 0;
    rep (i,K) rep(j,K) rep(l,K) sum += gcd(i, gcd(j, l));
    cout << sum;
}