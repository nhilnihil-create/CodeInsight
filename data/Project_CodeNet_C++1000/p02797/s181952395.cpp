#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    ll n,k,s,temp;
    cin>>n>>k>>s;
    if (s==1000000000)temp=1;
    else temp=s+1;
    vector<ll> a(n,temp);
    rep(i,k) {
        a[i]=s;
    }
    rep(i,n) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
