#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int MOD= 1e9+7;
int main(){
    long n,k,a=0,b=0;
    cin >> n >> k;
    long c[n];
    rep(i,n) cin >> c[i];
    rep(i,n)rep(j,n){
        if(c[j]<c[i]&&j<i) a++;
        if(c[j]<c[i]&&i<j) b++;
    }
    cout << ((((((k-k%2)/2)*(k-(k-1)%2))%MOD)*a)%MOD+(((((k+1-(k+1)%2)/2)*(k+1-k%2))%MOD)*b)%MOD)%MOD << endl;
}
