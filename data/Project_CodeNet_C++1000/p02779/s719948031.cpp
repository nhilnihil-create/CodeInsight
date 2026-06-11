#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    map<ll,ll> dict;

    map<ll,ll>::iterator it;

    ll t;
    cin>>t;
    while(t--) {
        ll num;
        cin>>num;
        if(dict.find(num)!=dict.end()) {
            cout<<"NO"<<endl;
            return 0;
        }
        else {
            dict[num]=1;
        }
    }
    cout<<"YES"<<endl;
}


