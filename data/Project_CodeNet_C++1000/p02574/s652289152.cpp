/*
    Author:zeke

    pass System Test!
    GET AC!!
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;
// cout << "Case #" << index << " :IMPOSSIBLE";
long long GCD(long long a,long long b){
    if(b==0)return a;
    return GCD(b,a%b);
}
long long LCM(long long a,long long b){
    return a*b/GCD(a,b);
}
const int N = pow(10,6)+10;

VV isp(N+1);

void sieve() {
  for (int i=2; pow(i,2)<=N; i++) {
    if (isp[i].size()==0) for(int j=2; i*j<=N; j++) {
        isp[i*j].push_back(j);
    }
  }
}//N以下の整数をふるってくれます
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    sieve();
    ll n;
    cin>>n;
    V vec(n);
    rep(i,n)cin>>vec[i];
    map<ll,ll> mp;
    bool h1=false;
    ll tempGCD=vec[0];
    rep(i,n){
        tempGCD=GCD(tempGCD,vec[i]);
    }
    if(tempGCD!=1){
        cout<<"not coprime"<<endl;
        return 0;
    }
    //V isp(1e6+10);
   // map<ll,ll> mp;
    rep(i,n){
        ll temp=vec[i];
        for(auto j:isp[vec[i]]){
            while(temp%j==0){
                temp/=j;
                if(mp[j]!=0){
                    h1=true;
                }
            }
        }
        if(mp[temp]!=0&&temp!=1){
            h1=true;
        }
        for(auto j:isp[vec[i]]){
            mp[j]++;
        }
        mp[temp]++;
    }
    if(h1){
        cout<<"setwise coprime"<<endl;
    }else{
        cout<<"pairwise coprime"<<endl;
    }
}
