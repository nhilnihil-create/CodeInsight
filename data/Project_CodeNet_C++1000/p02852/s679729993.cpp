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


void solve(long long N, long long M, string &S){
    reverse(ALL(S));
    vll rec;
    ll i=0, j;
    while(i < N){
        for( j = min(i+M, N); j >i; j--){
            if(S[j]=='0'){
                rec.push_back(j-i);
                break;
            }
        }
        if(j == i){
            cout<<-1<<endl; return;
        }
        else{ i = j;}
    }
    reverse(ALL(rec));
    for(auto x: rec) cout<<x<<" ";
    cout<<endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    string S;
    cin>>S;
    solve(N, M, S);
    return 0;
}
