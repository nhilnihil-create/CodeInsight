#include <bits/stdc++.h>
#define int long long

#define mp make_pair
#define pb push_back

const int mod = (int)1e9+7;
using namespace std;

int fastp(int a, int b){
    int res = 1;
    a %= mod;
    while(b){
        if(b&1) res = (res * a) % mod;
        a *= a; a %= mod;
        b >>= 1;
    }
    return res%mod;
}
signed main(){
    int n,a;
    cin >> n >> a;
    if(a == n+1){
        cout << 1;
        return 0;
    }
    int s1,s2;
    s1 = s2 = 0;
    int x1 = 0;
    for(int i =0;i<a;i++){
        s1 += x1;
        x1++;
    }
    int x2 = n;
    for(int i = 0;i<a;i++){
        s2 += x2;
        x2--;
    }
    int s = 0;
    for(int i = a;i<=n;i++){
        s += (s2-s1+1+mod)%mod;
        s %= mod;
        s2 += x2;
        s1 += x1;
        x1++;
        x2--;
    }
    cout << s+1;
}
