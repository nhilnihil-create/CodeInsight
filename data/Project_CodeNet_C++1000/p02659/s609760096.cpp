#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    ll a;
    int b1,b2;
    scanf("%lld %d.%d",&a, &b1,&b2);
    int b=100*b1+b2;
    cout << (ll)(a*b)/100;
}
