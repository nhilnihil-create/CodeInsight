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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    vector<bool> visited(1001001,true);
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]) visited[a[i]]=false;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int num=a[i];
        if(i>0 && a[i]==a[i-1]) continue;
        if(visited[num]) ans++;
        for(int times=1;num*times<1001001;times++){
            visited[num*times]=false;
        }
    }
    cout<<ans<<endl;
}