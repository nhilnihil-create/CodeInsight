#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fpow(ll b,ll p,ll mod){
    b %=mod;
    ll ans=1;
    while(p){

        if (p&1){
            ans *=b;
            ans %=mod;
        }
        b *=b;
        b%=mod;
        p >>=1;
    }
    return ans;
}

//long long fpow(long long a, long long n, long long mod)
//{
//    if (n == 0)        return 1;
//    else if (n & 1) return a * fpow(a, n - 1, mod) % mod;
//    else
//    {
//        long long num = fpow(a, n / 2, mod) % mod;
//        return num * num % mod;
//    }
//}
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int start=0;
    char now = 'R';
    int n = s.size();
    vector<int> a(n,1);
    for(int i=0;i<n;++i){
        if (s[i]=='R' && s[i+1]=='R'){
            a[i+2] += a[i];
            a[i] = 0;
        }
    }

    for(int i=n-1;i>=0;--i){
        if (s[i]=='L' && s[i-1]=='L'){
            a[i-2] += a[i];
            a[i] = 0;
        }
    }
    for(auto c:a) {
        cout << c << ' ';
    }
    return 0;
}
