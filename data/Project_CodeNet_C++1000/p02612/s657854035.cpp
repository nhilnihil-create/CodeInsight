#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
//    ll cost=n/1000;
    cout<<abs(n-ceil(n*1.0/1000*1.0)*1000);
    return 0;
}
