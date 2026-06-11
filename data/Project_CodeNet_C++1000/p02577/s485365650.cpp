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
    string n;
    cin>>n;
    ll cnt=0;
    rep(i,n.size()){
        cnt+=ll(n[i]-'0');
    }
    if (cnt%9==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}