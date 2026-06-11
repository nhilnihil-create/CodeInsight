#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back 
#define mp make_pair
#define f first
#define s second
#define sz(x) ((int)x.size())
const ll maxint=2e18;
const ll minint =-2e18;
/*******\
(͡ ° ͜ʖ ͡ °) : Hello there, relax.
\*     */

int main(){
    ll x,k,d;
    cin>>x>>k>>d;
    x = abs(x);
    ll n = min(k,x/d);
    k -= n;
    x -= (n*d);
    if(k == 0){
        cout<<x;
        exit(0);
    }
    if(k&1){
        cout<<abs(x-d);
    }else{
        cout<<x;
    }
    return 0;
}