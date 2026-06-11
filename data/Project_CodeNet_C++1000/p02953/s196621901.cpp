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
    vector<int> a(n);
    for(auto &c:a) cin >> c;
    if (n==1) cout << "Yes" << endl;
    else {
        for(int i=0;i<n-1;++i){
            if (a[i] - a[i+1] > 1){
                cout <<"No" << endl;
                return 0;
            }else if (a[i] - a[i+1] == 1){
                a[i+1] +=1;
            }
        }
        cout <<"Yes";
//


    }
    return 0;
}
