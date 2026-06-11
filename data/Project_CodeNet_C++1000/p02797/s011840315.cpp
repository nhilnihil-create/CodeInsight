#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k,s;
    cin >> n >> k >> s;
    ll INF = 1e9;
    if(s < INF){
        for(i = 0;i < k;++i){
            cout << s << endl;
        }
        for(i = k;i < n;++i){
            cout << INF << endl;
        }
    }else{
        for(i = 0;i < k;++i){
            cout << s << endl;
        }
        for(i = k;i < n;++i){
            cout << 1 << endl;
        }
    }

    return 0;
}