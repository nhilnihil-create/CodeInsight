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


void solve(long long N, std::vector<long long> A){
    if(N == 2){
        cout<< max(A[0], A[1]) - min(A[0], A[1])<<endl;
        cout << max(A[0], A[1])<<" "<< min(A[0], A[1])<<endl;
        return;
    }
    vll posEntry, negEntry, zeroEntry;
    vector<pll> res;
    REP(i, N){
        if(A[i]>0)
            posEntry.push_back(A[i]);
        else if(A[i]<0)
            negEntry.push_back(A[i]);
        else
            zeroEntry.push_back(A[i]);
    }
    //* ALL ZERO SPECIAL RETURN
    if(negEntry.size()==0 && posEntry.size()==0){
        cout<<0<<endl;
        REP(i, N-1){
            cout << 0 << " "<<0 <<endl;
        }
        return;
    }
    
    if(zeroEntry.size()==0 && negEntry.size()==0){
        //* all positive, special case
        sort(ALL(posEntry));
        reverse(ALL(posEntry));
        res.push_back(make_pair(posEntry.back(), posEntry[0]));
        negEntry.push_back(posEntry.back() - posEntry[0]);
        posEntry.pop_back();
        reverse(ALL(posEntry)); 
        posEntry.pop_back();
    }
    else if(zeroEntry.size()==0 && posEntry.size()==0){
        //* all negative, special case
        sort(ALL(negEntry));
        res.push_back(make_pair(negEntry.back(), negEntry[0]));
        posEntry.push_back(negEntry.back() - negEntry[0]);
        negEntry.pop_back();
        reverse(ALL(negEntry)); 
        negEntry.pop_back();
    }
    else if(zeroEntry.size()> 0 && negEntry.size()==0){
        negEntry.insert(negEntry.end(), ALL(zeroEntry));
    }
    else if(zeroEntry.size()> 0 ){
        posEntry.insert(posEntry.end(), ALL(zeroEntry));
    }

    //* now positive+negative only
    while(negEntry.size()>1){
        res.push_back(pll(posEntry.back(), negEntry.back()));
        posEntry.back() -= negEntry.back();
        negEntry.pop_back();
    }
    while(posEntry.size()>1){
        res.push_back(pll(negEntry.back(), posEntry.back()));
        negEntry.back()-= posEntry.back();
        posEntry.pop_back();
    }
    res.push_back(pll(posEntry.back(), negEntry.back()));

    cout << posEntry.back() -  negEntry.back() <<endl;
    for(auto x: res){
        cout<< x.first <<" "<<x.second<<endl;
    }
    return;
    

    
    
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
