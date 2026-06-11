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
int r[300001];
int c[300001];
ll ans;
int h,w,m;
int x,y;
int mxr,mxc;
int rr,cc;
set<pi<int,int>> s;
vector<int> vr,vc;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> h >> w >> m;
    mxr = mxc = -10;
    rep1(i,0,m){
        cin >> x >> y;
        r[x]++;
        c[y]++;
        s.insert({x,y});
    }    

    rep2(i,1,h) mxr = max(mxr,r[i]);
    rep2(i,1,w) mxc = max(mxc,c[i]);
    ans = mxr + mxc - 1;

    rep2(i,1,h) if(mxr == r[i]) vr.PB(i);
    rep2(i,1,w) if(mxc == c[i]) vc.PB(i);

    rep1(i,0,(int)vr.size())
        rep1(j,0,(int)vc.size())
            if(!s.count({vr[i],vc[j]})){
                cout << ans + 1 << '\n';
                return 0;
            }
    cout << ans;
    return 0;
}