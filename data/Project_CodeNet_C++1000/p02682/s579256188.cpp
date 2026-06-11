#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
 
int main() {
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    if (a>=k){
        cout<<k<<endl;
    }
    else if (a+b>=k){
        cout<<a<<endl;
    }
    else{
        cout<<(a-(k-(a+b)))<<endl;
    }
}