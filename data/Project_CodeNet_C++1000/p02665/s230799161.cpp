#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define pb(a) push_back(a)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

typedef long long unsigned int ull;
typedef long long int ll;
typedef pair<ll, ll> P;

int main()
{
    ll N;
    cin >> N;
    ll a[N+1];
    REP(i,N+1){
        cin >> a[i];
    }
    ll low[N+1],high[N+1];
    low[N] = a[N];
    high[N] = a[N];
    for(int n=N-1;n>=0;n--){
        low[n] = (low[n+1]+1)/2 + a[n];
        high[n] = high[n+1] + a[n];
    }

    if(low[0]>1 || high[0]<1){
        cout << -1 << endl;
        return 0;
    }

    ll d[N+1];
    d[0] = 1;
    ll sum = 1;
    for(int n=1;n<=N;n++){
        d[n] = min(high[n],(d[n-1]-a[n-1])*2);
        sum += d[n];
    }
    cout << sum << endl;
}