#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+233;


int main(){
    
    ll a;
    double b;
    cin>>a>>b;
    b+=0.0000001;
    b*=100;
    ll ans = a*(int)b/100;
    cout<<ans<<endl;
    
    return 0;
}