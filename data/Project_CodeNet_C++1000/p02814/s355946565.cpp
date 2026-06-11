#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

ll gcd(ll p, ll q){ 
    while(q != 0){
        ll r=p%q;
        p=q;
        q=r;
    }
    return p;
}

ll lcm(ll a, ll b)
{
    if((ll)a * b / gcd(a, b)>inf){
        cout<<0<<endl;
        exit(0);
    }
    else return (ll)a * b / gcd(a, b);
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),ca(n),ba(n);
    rep(i,0,n){
        cin>>a.at(i);
        ca.at(i)=a.at(i);
    }
    int cz=0;
    while(ca.at(0)%2==0){
        ca.at(0)/=2;
        cz++;
    }
    rep(i,1,n){
        int c=0;
        while(ca.at(i)%2==0){
            ca.at(i)/=2;
            c++;
        }
        if(cz!=c){
            cout<<0<<endl;
            return 0;
        }
    }
    rep(i,0,n){
        ba.at(i)=a.at(i)/2;
    }
    ll la=ba.at(0);
    rep(i,0,n){
        la=lcm(ba.at(i),la);
    }
    //cout<<la<<endl;
    if(m/la%2==0)cout<<m/la/2<<endl;
    else cout<<m/la/2+1<<endl;
return 0;
}