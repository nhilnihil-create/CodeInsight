#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
ll gcd(ll a, ll b)
{
    if (a%b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    /*ll e = c*d;
    for(ll i = 1;i < d;i++){
        if(c*i%d == 0){
            e = c*i;
            break;
        }
    }*/
    if(c<d)swap(c,d);
    ll e = lcm(c,d);
    ll ac = (a-1)/c;
    ll ad = (a-1)/d;
    ll acd = (a-1)/e;

    ll bc = b/c;
    ll bd = b/d;
    ll bcd = b/e;
    ll acnt = a-1-(ac+ad-acd);
    ll bcnt = b-(bc+bd-bcd);
    cout << bcnt-acnt << endl;
    //cout << bcnt << ' ' << acnt << endl;
    //cout << bc << ' ' << bd << ' ' << bcd << endl;
    return 0;
}