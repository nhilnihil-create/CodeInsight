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
    int n=100;cin>>n;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    sort(all(l));

    int cnt=0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            for (size_t k = j+1; k < n; k++)
            {
                if(l[i]!=l[j] && l[j]!=l[k] && l[k]!=l[i] && l[i] + l[j] > l[k]){
                    ++cnt;
                    // cout<<i+1<<' '<<j+1<<' '<<k+1<<endl;
                }
            }
            
        }
        
    }
    cout<<cnt<<endl;
    
}
