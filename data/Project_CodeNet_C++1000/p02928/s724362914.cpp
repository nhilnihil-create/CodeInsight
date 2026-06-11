#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stdio.h>
#include <math.h>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef queue<int> qi;
typedef queue<string> qs;




#define rep(i, n) for(ll i=0; i<(n); ++i)
#define repp(i, a, b) for(ll i = (a); i <= (b); i++)

const ll MOD=pow(10, 9) + 7;


int main(void){
    ll n, k;
    cin >> n >> k;
    vll A(2010);
    rep(i, n) cin >> A[i];
    

    //１ループ内の転倒数
    ll cnt1 = 0;
    rep(i, n-1) repp(j, i+1, n-1){
        if(A[i] > A[j]) cnt1++;
    }
    cnt1 *= k;
    cnt1 %= MOD;

    //外の転倒数
    ll cnt2 = 0;
    rep(i, n) rep(j, n){
        if(A[i] > A[j]) cnt2++;
    }
    cnt2 *= (k*(k-1)/2 %MOD);

    ll cnt = (cnt1 + cnt2) % MOD;
    cout << cnt << endl;
}