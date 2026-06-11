#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int gc(ll N){
    ll ans=N;
    rep(i,sqrt(N)+1){
      ll p=sqrt(N)+1-i;
        if(N%p==0){
            ans=p;
          break;
        }
    }
    return ans;
}
int main() {
 ll N;
 cin>>N;
 cout<<gc(N)+N/gc(N)-2<<endl;
}
