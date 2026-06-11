#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>

using namespace std;

typedef long long ll;

#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep1(i,n) for(int i=1; i<=(int)(n); i++)
#define all(c) c.begin(),c.end()
#define psb push_back
#define ppb pop_back

const int INF = 1001001001;

int main() {
    string T;

    cin >> T;

    rep (i, T.size()) {
        if (T[i] == '?') T[i] = 'D';
    }

    cout << T << endl;
}
