// C - Sum of gcd of Tuples(Easy)
#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int gcd(int x, int y){
    return (x%y) ? gcd(y, x%y) : y;
}

int main(){
    int k;
    cin >> k;
    int ans = 0;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            for(int l=1; l<=k; l++){
                int a = gcd(i, gcd(j, l));
                ans += a;
            }
        }
    }
    cout << ans << endl;
    return 0;
}