#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    int k;
    int sum=0;
    cin >> k;
    rep2(a,1,k+1){
        rep2(b,1,k+1){
            rep2(c,1,k+1){
                sum+= __gcd(a,__gcd(b,c));
            }
        }
    }

    cout << sum;

    return 0;
}