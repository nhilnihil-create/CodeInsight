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
int N,K;
ll p[5001];
ll c[5001];
ll ans;
ll ret,cnt;
int here;
ll path,ct;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> N >> K;
    rep1(i,0,N) cin >> p[i], --p[i];
    rep1(i,0,N) cin >> c[i];

    ans = -INF;
    rep1(i,0,N){
        here = i;
        ret = cnt = 0;

        while(1){
            cnt++;
            ret += c[here];
            here = p[here];
            if(i == here) break;
        }
        path = ct = 0;

        while(1){
            ct++;
            path += c[here];

            if(ct > K) break;

            ll t = (K - ct) / cnt;
            ll score = path + max(0LL,ret) * t;
            ans = max(ans,score);

            here = p[here];
            if(i == here) break;
        }
    }

    cout << ans;
    return 0;
}
