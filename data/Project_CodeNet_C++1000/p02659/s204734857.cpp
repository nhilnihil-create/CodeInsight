#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll a;
    string b;
    cin>>a>>b;
    ll B=0;
    B+=100*(b[0]-'0');
    B+=10*(b[2]-'0');
    B+=(b[3]-'0');

    ll ans=a*B/100;

    cout<<ans<<endl;
}