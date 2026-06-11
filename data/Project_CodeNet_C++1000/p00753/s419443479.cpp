#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define rep(i, n) for(int i=0; i<(n); ++i)

const int max_n = 1000000;
int prime[max_n];

int main(void){
    rep(i, max_n) prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for(int i=2; i<=sqrt(max_n)+1; ++i) {
        if(prime[i] == 1) {
            for(int j=2; i*j<=max_n; ++j) {
                prime[i*j] = 0;
            }
        }
    }
    int n;
    while(cin >> n && n) {
        int ans = 0;
        for(int i=n+1; i<=2*n; ++i) {
            ans += prime[i];
        }
        cout << ans << endl;
    }
}