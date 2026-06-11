#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

//yakusuu rekkyo
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // push its partner
            if (N/i != i) res.push_back(N/i);
        }
    }

    sort(res.begin(), res.end());
    return res;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // exponential

        // divide as much as you can
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // push the result
        res.push_back({a, ex});
    }

    // last num (if the lasting n is prime number and not 1)
    if (N != 1) res.push_back({N, 1});
    return res;
}



int main() {
    pair<bool,int> pr[100001];
    int n,m; cin >> n >> m;
    int p;
    string s;
    int ansAC = 0;
    int ansWA = 0;
    rep(i,100001){
        pr[i].first = false;
        pr[i].second = 0;
    }
    rep(i,m){
        cin >> p >> s;
        if(s == "AC"){
            pr[p].first = true;
        }
        else if(pr[p].first == false){
            pr[p].second ++;
        }
    }

    rep(i,100001){
        if(pr[i].first == true){
            ansWA += pr[i].second;
            ansAC ++;
        }
    }

    cout << ansAC <<" "<< ansWA;
    return 0;
}









