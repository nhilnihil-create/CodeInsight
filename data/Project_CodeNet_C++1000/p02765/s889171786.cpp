#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n,r;cin >> n >> r;
    if(n < 10){
        r += 100*(10 - n);
    }
    cout << r;
    return 0;
}