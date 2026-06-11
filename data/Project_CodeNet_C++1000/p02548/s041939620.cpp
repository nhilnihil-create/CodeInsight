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
    int n;cin>>n;
    int a=1,b=1,c=1;
    int sum=0;
    for (a = 1; a < n; a++)
    {
        for (b = 1; a*b < n; b++)
        {
            ++sum;
        }
        
    }
    cout<<sum<<endl;
    
}

