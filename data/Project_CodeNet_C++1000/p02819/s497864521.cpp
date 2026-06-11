#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

bool prime(ll n){
    if(n==2) return true;
    else if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0) return false;
    }
    return true;
}

int main(void)
{
    ll n;
    cin >> n;
    while(1){
        if(prime(n)){
            cout << n << endl;
            break;
        }else n++;
    }
    return 0;
}