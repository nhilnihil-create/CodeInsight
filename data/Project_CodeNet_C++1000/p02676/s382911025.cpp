#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
 
int main() {
    ll k;
    string s;
    cin>>k>>s;
    if (s.size()>k){
        s=s.substr(0,k)+"...";
    }
    cout<<s<<endl;
}