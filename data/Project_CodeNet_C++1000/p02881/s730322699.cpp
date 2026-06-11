#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    ll limits=sqrt(n+0.5);
    ll ans1=-1;
    for(ll i=1;i<=limits;i++){
        if(!(n%i)){
            ans1=i;
        }
    }
    ll ans2=n/ans1;
    cout<<(ans1-1)+(ans2-1);
    return 0;
}
