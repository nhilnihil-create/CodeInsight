#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    int n;
    cin>>n;

    cout<<fixed<<endl;
    cout<<setprecision(12)<<endl;

    double ans;
    ans=(double(n)/3)*(double(n)/3)*(double(n)/3);

    cout<<ans<<endl;
}


