#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=1<<18;


int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    vector<ll> f(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<n;i++) cin>>f[i];
    sort(a.begin(),a.end());
    sort(f.begin(),f.end(),greater<ll>());

    ll ub=100100100100100;
    ll lb=-1;

    while(ub-lb>1){
        ll med=(ub+lb)/2;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(med<a[i]*f[i]) cnt+=a[i]-med/f[i];
        }
        if(cnt>k){
            lb=med;
        }else{
            ub=med;
        }
    }

    ll cnt=0;
    for(ll i=0;i<n;i++){
        cnt+=a[i]-lb/f[i];
    }

    cout<<ub<<endl;
 
}