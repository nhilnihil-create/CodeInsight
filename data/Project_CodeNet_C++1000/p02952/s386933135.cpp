#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//ll fpow(ll b,ll p,ll mod){
//    b %=mod;
//    ll ans=1;
//    while(p){
//
//        if (p&1){
//            ans *=b;
//            ans %=mod;
//        }
//        b *=b;
//        b%=mod;
//        p >>=1;
//    }
//    return ans;
//}


int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
        int res=0;
    for(int i=1;i<=n;++i){
        if (1<= i && i<=9) res++;
        else if (100<=i && i<=999) res++;
        else if (10000<=i && i<=99999) res++;
    }
    cout << res ;
    return 0;
}
