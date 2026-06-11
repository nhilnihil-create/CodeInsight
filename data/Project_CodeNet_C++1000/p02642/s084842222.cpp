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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<bool> flags(10000000,false);
    for(int i=0;i<n;i++){
        cin>>a[i];
        flags[a[i]]=true;
    }
    sort(a.begin(),a.end());
    for(int now=a[0];now<1000005;){
        now+=a[0];
        flags[now]=false;
    }
    for(int i=1;i<n;i++){
        int now=a[i];
        if(now==a[i-1]){
            flags[now]=false;
            continue;
        }
        while(now<1000005){
            now+=a[i];
            flags[now]=false;
        }
    }
    int ans=0;
    for(int i=0;i<1000005;i++){
        if(flags[i]) ans++;
    }
    cout<<ans<<endl;
}