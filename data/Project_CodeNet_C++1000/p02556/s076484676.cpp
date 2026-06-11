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
int n;
ll x,y;
ll X[200000];
ll Y[200000];
ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ans = -8e18;
    rep1(i,0,n){
        cin >> x >> y;
        X[i] = x+y;
        Y[i] = y-x;
    }

    sort(X,X+n);
    sort(Y,Y+n);
    ans = max(abs(X[0]-X[n-1]),abs(Y[0]-Y[n-1]));
    cout << ans;
    return 0;
}