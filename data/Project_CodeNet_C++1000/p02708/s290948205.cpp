#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;

int main(){
    int n,k;cin>>n>>k;
    ll ans=1;
    vector<ll> a(n+1);
    a[0]=0;
    for(int i=1;i<n+1;i++){
        a[i]=a[i-1]+i;
    }
    for(int i=k;i<n+1;i++){
        ans+=(a[n]-a[n-i])-a[i-1]+1;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
