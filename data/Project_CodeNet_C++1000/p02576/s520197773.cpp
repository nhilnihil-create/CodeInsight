#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi = 3.14159265358979323846;
 
int main() {
    ll n,x,t;
    cin>>n>>x>>t;
    if (n%x==0){
        cout<<(n/x)*t<<endl;
    }
    else{
        cout<<(n/x+1)*t<<endl;
    }
}