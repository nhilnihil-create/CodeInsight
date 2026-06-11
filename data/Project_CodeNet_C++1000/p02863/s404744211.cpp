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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
int dpl[3010][3010];
int dpr[3010][3010];

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t;j++){
            dpl[i][j]=dpl[i-1][j];
            int from=j-a[i];
            if(from>=0) dpl[i][j]=max(dpl[i][j],dpl[i-1][from]+b[i]);
        }
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<=t;j++){
            dpr[i][j]=dpr[i+1][j];
            int from=j-a[i];
            if(from>=0) dpr[i][j]=max(dpr[i][j],dpr[i+1][from]+b[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<t;j++){
            ans=max(ans,b[i]+dpl[i-1][j]+dpr[i+1][t-j-1]);
        }
    }
    cout<<ans<<endl;
}