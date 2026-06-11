#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    ll s;
    cin>>s;

    ll x1=1000000000;
    ll x2=1;

    ll y2=(s+x1-1)/x1;
    ll y1=(x1*y2-s);

    cout<<0<<" "<<0<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

}