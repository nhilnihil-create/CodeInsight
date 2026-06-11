
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
ll ans;
ll a[100000];
ll LIMIT = 1e18;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    rep1(i,0,n){
        cin >> a[i];
        if(!a[i]){
            cout << 0;
            return 0;
        }
    }

    ans = 1;
    rep1(i,0,n){
        if(ans > LIMIT/a[i]){
            cout << -1;
            return 0;
        }
        ans *= a[i];
    }

    cout << ans;
    return 0;   
}

