#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define elnd endl //* missspell check
const ll INF = 1LL << 60;


void solve(std::vector<long long> T, std::vector<long long> A, std::vector<long long> B){
    ll T1 = T[0], T2 = T[1], A1 = A[0], A2 = A[1], B1 = B[0], B2 = B[1];
    ll TA1 = T1 * A1, TA = TA1 + T2 * A2, TB1 = T1 * B1, TB = TB1 + T2 * B2;
    if(TA == TB){
        cout<< "infinity"<<endl;
        return;
    }
    ll WT = T1 + T2;
    if(TA > TB) {
        swap(TA, TB); swap(TA1, TB1);
    }
    //* NOW TA < TB
    if(TB1 > TA1) {
        cout<<0<<endl; return;
    }

    ll delta = TB - TA;
    ll ans = (TA1 - TB1 +1 + delta - 1) / delta;
    if(ans == 1) cout<< 1<<endl;
    else if((ans -1) * delta == TA1 - TB1){
        cout<< 2*ans - 2<<endl;
    }
    else{
        cout<<2*ans-1<<endl;
    }
    
    
}

int main(){
    std::vector<long long> T(2);
    for(int i = 0 ; i < 2 ; i++){
        scanf("%lld",&T[i]);
    }
    std::vector<long long> A(2);
    for(int i = 0 ; i < 2 ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(2);
    for(int i = 0 ; i < 2 ; i++){
        scanf("%lld",&B[i]);
    }
    solve(std::move(T), std::move(A), std::move(B));
    return 0;
}
