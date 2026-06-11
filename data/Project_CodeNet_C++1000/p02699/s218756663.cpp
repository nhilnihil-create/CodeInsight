#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)
using namespace std;

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))
#define rep(i,n) for(long long i = 0;i < n;i++)

using ll = long long;
using ull = unsigned long long;
using llv = vector<long long>;

int main(void){
    ll s,w;
    cin >> s >> w;
    cout << (s <= w ? "unsafe" : "safe") << endl;
}