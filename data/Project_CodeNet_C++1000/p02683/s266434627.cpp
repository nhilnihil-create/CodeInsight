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
#define INF 9999999999999
const double PI = acos(-1.0);
int N,M,X;
ll ans,ret;
struct book{
    int p;
    int a[12];
};
book b[12];
int skill[12];
bool ok;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> N >> M >> X;
    rep1(i,0,N){
        cin >> b[i].p;
        rep1(j,0,M)
            cin >> b[i].a[j];
    }

    ans = INF;
    for(int i = 0; i < (1 << N); i++){
        ret = 0;
        ok = true;
        memset(skill,0,sizeof(skill));
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                rep1(k,0,M) skill[k] +=b[j].a[k];
                ret += b[j].p;
            }
        }
        rep1(j,0,M)
            if(skill[j] < X)
                ok = false;
        if(ok) ans = min(ans,ret);
    }
    if(ans == INF) cout << -1;
    else cout << ans;

    return 0;
}