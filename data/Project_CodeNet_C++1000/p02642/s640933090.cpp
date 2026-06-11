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
ll a[200000];
ll cnt[1000001];
ll ans;
bool ok[1000001];
ll mx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    mx = -INF;
    rep1(i,0,n){
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }

    rep2(i,1,mx){
        if(cnt[i]){
            for(int j = i + i; j <= mx; j += i)
                ok[j] = true;
        }
    }

    rep1(i,0,n)
        if(cnt[a[i]] == 1 && !ok[a[i]]) ans++;
    
    cout << ans;
	return 0;
}
