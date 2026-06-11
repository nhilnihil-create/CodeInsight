#include<atcoder/all>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
using namespace atcoder;

#define ll long long
#define pal pair<ll,ll>
#define pad pair<double,double>
#define PB push_back
#define MP make_pair
#define F first
#define S second



int main(){
    ll n,q;
    cin >> n >>q;
    dsu d(n);
    for(ll i=0;i<q;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            cout << d.same(b,c) << endl;
        }else{
            d.merge(b,c);
        }
    }
}