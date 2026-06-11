#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    ll s;
    cin >> s;
    ll v = 1000000000;
    ll x = (v-s % v)%v;
    ll y = (s+x) / v;
    printf("0 0 1000000000 1 %lld %lld\n", x, y);
    return 0;
}
