#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n,m;
    cin >> n >> m;
    rep(i,m+1){
        if(i==0) continue;
        if(n==4) print("2 3");
        else if(i==1) print(i<<" "<<n-i);
        else if(i<=(n/2-1)/2 && !(n&1)) print(i<<" "<<n-i);
        else print(i<<" "<<n-i-1+(n&1));
    }
    return 0;
}