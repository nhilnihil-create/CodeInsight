#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>
#include<tuple>
#include<bitset>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << fixed << setprecision(7) << (x) << endl;
#define printbit(x) cout << bitset<15>(x) << endl;
using ll = long long int;

ll ans;


long double pi = 3.14159265359;



ll gcd(ll a, ll b){ 
    if(b == 0) return a;
    return gcd(b,a%b);
}

vector<int> factorize(ll n){
    vector<int> resvec;
    for(ll i= 2;i*i <= n; ++i){
        if(n%i) continue;
        resvec.push_back(i);
        while(n%i == 0){
            n = n/i;
        }
    }
    if(n != 1) resvec.push_back(n);
    return resvec;
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll g = gcd(a,b);
    // cout << g << endl;
    vector<int> v = factorize(g);
    ans = v.size() + 1;
    cout << ans << endl;

return 0;
}