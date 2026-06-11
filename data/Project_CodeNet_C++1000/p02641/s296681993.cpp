#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;


int main(){
    int x,n;
    cin>>x>>n;
    vector<bool> f(110,true);
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        f[p]=false;
    }
    int ans=0;
    int dis=100100;
    for(int i=0;i<=101;i++){
        if(!f[i]) continue;
        if(abs(x-i)<dis){
            ans=i;
            dis=abs(x-i);
        }
    }
    cout<<ans<<endl;
}
