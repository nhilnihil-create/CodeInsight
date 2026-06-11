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
ll n,m,k;
ll a[200000];
ll b[200000];
ll ans;
ll ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m >> k;
    rep1(i,0,n) cin >> a[i];
    rep1(i,0,m) cin >> b[i];
    int i = 0,j = 0;

    while(j < m && ret + b[j] <= k) ret += b[j++];
    ans = j;
    while(i < n){
        ret += a[i++];
        while(ret > k && j > 0) ret -= b[--j];
        if(ret <= k) ans = max(ans, (ll)i + j);
    }
    cout << ans;
    return 0;  
}