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
    string s,t;cin>>s>>t;

    int ans=t.size();

    rep(start, s.size()-t.size()+1){
        int diff=0;
        rep(i,t.size()){
            if(t[i]!=s[start+i]) ++diff;

        }
        ans=min(ans,diff);
    }
    cout<<ans<<endl;
}

