#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;
using ll = long long;
constexpr ll INF = 1010000000000000017LL;
constexpr ll mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    string n;
    cin>>n;

    ll sum = 0;
    rep(i, n.size()){
        sum+=n[i]-'0';
    }

    cout<<((sum%9==0) ? "Yes" : "No")<<endl;
}
