#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll n; cin>>n;
    for(int i=1;i<=50000;i++){
        if(i*108/100 == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}