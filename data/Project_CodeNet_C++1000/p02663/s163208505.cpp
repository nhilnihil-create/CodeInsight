#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    cout<<(h2-h1)*60+(m2-m1)-k;
    
}
