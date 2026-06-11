//Moh_K_Imar .......
//28/08/2020  ... 11,30.
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll x=a+b; ll y=a+c; ll z=b+c;
    ll v=min(x,y);
    cout<<min(v,z)<<endl;

    return 0;
}

