#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9;
int main(){
    ll s;
    cin>>s;
    ll y2=ceil((1.0*s)/(1.0*INF));
    ll x2=y2*INF-s;
    cout<<"0 0 1000000000 1"<<" "<<x2<<" "<<y2;
}
