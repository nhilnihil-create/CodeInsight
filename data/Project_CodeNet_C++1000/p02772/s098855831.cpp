#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    ll n;
    cin>>n;

    vector<ll> even;

    while(n--) {
        ll num;
        cin>>num;

        if(num%2==0) {
            even.push_back(num);
        }
    }

    bool condition=true;
    for(int i=0;i<even.size();i++) {
        if(even[i]%3!=0&&even[i]%5!=0) {
            condition=false;
        }
    }

    if(condition) cout<<"APPROVED"<<endl;
    else cout<<"DENIED"<<endl;
}


