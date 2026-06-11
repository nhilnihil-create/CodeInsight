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
int h,w,k;
int ret;
int ans;
char board[6][6];

int hasBit(int s, int num){
    return (s >> num) & 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> h >> w >> k;
    rep1(i,0,h)
        rep1(j,0,w)
            cin >> board[i][j];

    for(int r = 0; r < (1 << h); r++){
        for(int c = 0; c < (1 << w); c++){
            ret = 0;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(hasBit(r,i) && hasBit(c,j) && board[i][j] == '#') ret++;
                }
            }
            if(ret == k) ans++;
        }
    }
    cout << ans;
    return 0;  
}
