#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    ll n;
    cin>>n;
    ll ans = n*(n-1)/2;
    cout<<ans<<endl;

    return 0;
}
