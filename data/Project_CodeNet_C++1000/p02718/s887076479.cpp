/*     <<<  J A I ~ S H R E E ~ R A M  >>>     */

// Title: abc161_b.cpp
// created on: 13-07-2020 at 21:20:58
// Creator & Template : Udit Gupta "@luctivud"
// https://github.com/luctivud
// https://www.linkedin.com/in/udit-gupta-1b7863135/


#include "bits/stdc++.h"
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

using namespace std;

const long long int MOD_JOHAN {1000000007};
const long long int MOD_LIGHT {998244353};
const long long int MAXN_EYEPATCH = 1e6 + 1LL;
const long long int MAXN_FULLMETAL = 501LL;

typedef long long int lld;
typedef unsigned long long int llu;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef vector<string> v_str;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define                   GREED_FOR_SPEED   ios_base::sync_with_stdio(false); cin.tie(0)
#define             TESTCASES_ARE_THERE()   _SC4N(Test0xcs); TotalT35tC4ses = Test0xcs; while(Test0xcs--)
#define                  _INP47T(V3CT07_)   for(auto &V3CT07____IT7T : V3CT07_) cin >> (V3CT07____IT7T)
#define                  mems(A77AY,V4LU)   memset((A77AY), V4LU, sizeof((A77AY)))
#define   FOR4WD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T; IT7T < E9xD; IT7T += St3P)
#define   FOR8WD(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T; IT7T > E9xD; IT7T -= St3P)
#define  FOR4NGE(IT7T, ST47T, E9xD, St3P)   for(auto IT7T = ST47T;((St3P<0) ? IT7T>E9xD : IT7T<E9xD); IT7T += St3P)
#define            FOR34CH(V3CT07_, IT7T)   for(auto IT7T = V3CT07_.begin(); IT7T != V3CT07_.end(); IT7T++)
#define           FORA77L(V3CT07_s, IT7T)   for (auto IT7T : V3CT07_s)
#define                   AL47L(V3CT07_t)   V3CT07_t.begin(), V3CT07_t.end()
#define             L3N(V3CT07_x, Typ30F)   (Typ30F) V3CT07_x.size()
#define                              endl   "\n"
#define                                PI   3.1415926535897932384626433832795
#define                          INF1N1TY   1000000000000000005LL;
#define                            un_map   unordered_map
#define                            un_set   unordered_set


template<typename T> void _SC4N(T &x) { 
    x = 0; bool neg = 0; 
    register T c = getchar();
    if (c == '-') neg = 1, c = getchar();
    while ((c < 48) || (c > 57)) c = getchar();
    for ( ; c < 48||c > 57 ; c = getchar());
    for ( ; c > 47 && c < 58; c = getchar() ) x= (x << 3) + ( x << 1 ) + ( c & 15 );
    if (neg) x *= -1;
}


template <typename Type30F1, typename Type30F2> class _C0UN73R {

    public: map <Type30F1, Type30F2> CountOfElements;

    private: static bool asc(pair<Type30F1, Type30F2>& a, pair<Type30F1, Type30F2>& b) {
        return (a.second < b.second); 
    } 

    private: static bool dsc(pair<Type30F1, Type30F2>& a, pair<Type30F1, Type30F2>& b) {
         return (a.second > b.second); 
    }

    public: _C0UN73R(vector<Type30F1> ArrayToCountValues) {
        for (auto elementInArray : ArrayToCountValues) {
            CountOfElements[elementInArray]++;
        }
    }

    map <Type30F1, Type30F2> getCountAsMap() {
        return CountOfElements;
    }

    vector<pair<Type30F1, Type30F2>> getSortedVectorPair(bool reverse = false) { 
        vector<pair<Type30F1, Type30F2>> SortedVector; 
        for (auto& it : CountOfElements) SortedVector.push_back(it);
        if (reverse) {
            sort(SortedVector.begin(), SortedVector.end(), dsc);
        } else {
            sort(SortedVector.begin(), SortedVector.end(), asc);
        }
        return SortedVector;
    } 
    // _C0UN73R <string , int> Obj(arr);
    // map<string, int> count =  Obj.getCountAsMap();
    // vector<pair<string, int>> sorted_count = Obj.getSortedVectorPair(true);
};


void printYesNo(bool Expr, int YNType = 1, string FirstChoice = "Ud", string SecondChoice = "Ud") { 
    if (YNType == 1) puts(Expr ? "YES" : "NO");
    else if (YNType == 2) puts(Expr ? "Yes" : "No");
    else if (YNType == 3) puts(Expr ? "yes" : "no");
    else if (YNType == 4) cout << (Expr ? FirstChoice : SecondChoice);
}



void solveEach(lld T35TC453N = 1) {
    lld n, m; cin >> n >> m;
    v_lld arr(n); _INP47T(arr);

    lld totalNumberOfVotes = accumulate(AL47L(arr), 0LL);

    sort(AL47L(arr), greater<int>());
    // cout << totalNumberOfVotes << " " << arr[m-1];
    printYesNo((float)arr[m-1]>=((float)totalNumberOfVotes/(4*m)), 2);


    // cout << "\n"; 
    return;
}


signed main() {

    // GREED_FOR_SPEED;

    lld Test0xcs = 0, TotalT35tC4ses = 1;

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    // TESTCASES_ARE_THERE()
        solveEach(TotalT35tC4ses - Test0xcs);
    return 0;
}

/*
THE LOGIC AND APPROACH IS MINE ( UDIT GUPTA )
SOME PARTS OF THE CODE MAY HAVE BEEN TAKEN FROM WEBSITES LIKE::
(I Own the code if no link is provided here or I may have missed mentioning it)ch|=spacelo &=_up change case
*/