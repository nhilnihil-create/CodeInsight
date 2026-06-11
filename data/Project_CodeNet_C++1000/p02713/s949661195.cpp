
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int gcd(int m, int n){
    if(n==0) return m;
    else return gcd(n,m%n);
}

int main(){
    int k;
    cin >> k;
    ll ans=0;
    for(int a=1; a<=k; a++){
        for(int b=1; b<=k; b++){
            for(int c=1; c<=k; c++){
                int abgcd, abcgcd;
                abgcd = gcd(a,b);
                abcgcd = gcd(abgcd,c);
                ans += abcgcd;
            }
        }
    }
    cout << ans << endl;

   

}