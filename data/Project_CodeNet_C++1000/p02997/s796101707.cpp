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
#define enld endl //* missspell check
const ll INF = 1LL << 60;

void solve(long long N, long long K){
    if(K > (N-1)*(N-2)/2){
        cout<<-1<<endl; return;
    }
    K = (N-1)*(N-2)/2 - K;
    cout << K+N-1 << endl;;
    for(ll i=2; i <= N; i++){
        cout << "1 " << i<< endl;
    }
    for(ll i=2; i<N; i++){
        if(K == 0) break;
        for(ll j = i+1; j <= N; j++){
            if(K == 0) break;
            cout<< i <<" "<<j<<endl;
            K--;
        }
    }

    
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    solve(N, K);
    return 0;
}
