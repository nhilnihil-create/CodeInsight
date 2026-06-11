#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    ll h,n;
    cin>>h>>n;

    while(n--) {
        ll attack;
        cin>>attack;

        h-=attack;
    }

    if(h<=0) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}


