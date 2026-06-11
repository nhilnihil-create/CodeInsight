#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;


void Main(){
    ll K;
    sll(K);
    ll V = 7;
    ll idx = 1;

    bool not_found = false;
    while(idx < 2*K){
        if(V % K==0){
            not_found = false;
            break;
        }else{
            not_found = true;
        }
        V = (V * 10 + 7) % K;
        ++idx;
    }

    if(not_found){
        cout << "-1" <<endl;
    }else{
        cout << idx <<endl;
    }


}

int main(){
    Main();
}