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
#define LB lower_bound
#define UP upper_bound
#define INF 999999999999
const double PI = acos(-1.0);
int N;
ll M,H;
ll h[100001];
ll mx[100001];
ll ans;
ll u,v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> N >> M;
    rep2(i,1,N){
        cin >> h[i];
        mx[i] = 0;
    }

    rep1(i,0,M){
        cin >> u >> v;
        mx[u] = max(mx[u],h[v]);
        mx[v] = max(mx[v],h[u]);
    }

    rep2(i,1,N)
        if(mx[i] < h[i]) ans++;
    cout << ans;
    return 0;     
}