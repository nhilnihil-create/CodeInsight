#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;
const ll inf=2e9,MOD=998244353,MAX=1e7+2;
vector<ll>v;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    ll n;
    cin>>n;
    map<ll,ll>mp;
    for(ll i=2;i*i<=n;i++){
        while(n%i==0)
            n/=i,mp[i]++;
    }
    if(n>1)
        mp[n]++;
    for(auto i:mp)
        v.pb(i.second);
    ll res=0;
    lp(i,0,sz(v)){
        ll x=1,y=0;
        while(x*(x-1)/2<=v[i])
            x++,y++;
        res+=y-1;
    }
    cout<<res;
}