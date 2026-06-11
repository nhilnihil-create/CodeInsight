#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <utility>
using namespace std;
int ky[8] = {-1,1,-2,2,-2,2,-1,1}; 
int kx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int ddy[8] = {-1,0,1,-1,1,-1,0,1};
int ddx[8] = {-1,-1,-1,0,0,1,1,1};
typedef long long ll;
#define pi pair
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define rep1(i,a,b) for(int i = a; i < b; i++)
#define rep2(i,a,b) for(int i = a; i <= b; i++) 
#define INF 999999999999
const double PI = acos(-1.0); 
ll n;
vector<ll> v;
map<ll,ll> m;
ll ans;

ll compute(ll num){
    ll mx = -INF;
    for(ll i = 1; i <= num; i++)
        if(i * (i + 1) / 2 <= num)
            mx = max(mx, i);
    return mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(ll i = 2; i * i <= n; i++){
        while(n % i == 0){
            v.PB(i);
            n /= i;
        }
    }
    if(n > 1) v.PB(n);

    ll vs = v.size();
    rep1(i,0,vs) m[v[i]]++;

    for(auto c : m){
       // if(c.S == 1) ans++;
        ans += compute(c.S);
    }
    cout << ans;
	return 0;
}
