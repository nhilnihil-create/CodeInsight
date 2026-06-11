#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    ll N, a, b;
    cin >> N >> a >> b;
    ll ans;
    if((a-b)%2 == 0){
        ans = min({(b-a)/2, b-1, N-a, (2*N-a-b)/2, (a+b)/2});
    }else{
         ans = min({b-1, N-a, (2*N+1-a-b)/2, (a+b-1)/2});
    }
    cout << ans << endl;
}