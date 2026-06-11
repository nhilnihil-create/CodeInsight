#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
 
int main() {
    ll n;
    cin>>n;
    vector<ll> hon={2,4,5,7,9};
    vector<ll> pon={0,1,6,8};
    vector<ll> bon={3};
    n%=10;
    rep(i,hon.size()){
        if (n==hon.at(i)){
            cout<<"hon"<<endl;
            return 0;
        }
    }
    rep(i,pon.size()){
        if (n==pon.at(i)){
            cout<<"pon"<<endl;
            return 0;
        }
    }
    rep(i,bon.size()){
        if (n==bon.at(i)){
            cout<<"bon"<<endl;
            return 0;
        }
    }
}