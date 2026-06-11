#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
using ll = long long;
using plong = pair<ll,ll>;
ll MOD=998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll H,W,A,B;
    cin>>H>>W>>A>>B;
    for(ll i=0;i<B;i++){
        for(ll i=0;i<A;i++){
            cout<<0;
        }
        for(ll i=0;i<W-A;i++){
            cout<<1;
        }
        cout<<"\n";
    }
    for(ll i=0;i<H-B;i++){
        for(ll i=0;i<A;i++){
            cout<<1;
        }
        for(ll i=0;i<W-A;i++){
            cout<<0;
        }
        cout<<"\n";
    }


}