#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll gcd(ll a, ll b){
    if(a < b)  swap(a,b);
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
ll ngcd(vector<ll> a){
    ll res;
    res = a[0];
    for(int i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll nlcm(vector<ll> numbers) {
    ll res;
    res = numbers[0];
    for (ll i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
    return res;
}
int main(){
    cout << fixed << setprecision(10);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll minc, maxc, mind, maxd, mincd, maxcd;
    if(a%c == 0) minc = a;
    else minc = (a/c+1)*c;

    if(a%d == 0) mind = a;
    else mind = (a/d+1)*d;
    /*
    cout << mind << endl;
    cout << "?? " << a << " " << d << endl; */
    maxc = (b/c)*c;
    maxd = (b/d)*d;

    ll cd = lcm(max(c,d),min(c,d));

    if(a%cd == 0) mincd = a;
    else mincd = (a/cd+1)*cd;

    maxcd = (b/cd)*cd;

    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;

    if(minc <= maxc) cnt1 = (maxc - minc) / c + 1;
    if(mind <= maxd) cnt2 = (maxd - mind) / d + 1;
    if(mincd <= maxcd)  cnt3 = (maxcd - mincd) / cd + 1;
    /*cout << minc << " " << maxc << endl;
    cout << mind << " " << maxd << endl;
    cout << mincd << " " << maxcd << endl;
    cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << endl;*/ 
    cout << (b - a) + 1 - cnt1 - cnt2  + cnt3 << endl;

    return 0;
}