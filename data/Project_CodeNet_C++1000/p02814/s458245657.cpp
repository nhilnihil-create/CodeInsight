#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;


int main(){
    ll n,m; cin >> n >> m;
    ll l,hl; l=hl=1;
    int fun;
    rep(i,n){
        ll a; cin >> a;
        l=lcm(l,a);
        hl=lcm(hl,a/2);
        int tmp=0;
        while(a%2==0){
            tmp++;
            a/=2;
        }
        if(i==0) fun=tmp;
        else if(fun!=tmp || hl>m){
            cout << 0 << endl;
            return 0;
        }
    }
    if(m<hl) cout << 0 << endl;
    else cout << ((m-hl)/l)+1 << endl;
return 0;
}
