//Bismillahir Rahmanir Raheem
//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<queue>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<deque>
#include<set>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long LL;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef pair<int, int> pii;
#define FF first
#define SS second
#define MP make_pair
#define mxN (int)2e5 + 2
#define sz(n) (int)(n).size()
#define fasterIO ios::sync_with_stdio(0); cin.tie(0);
LL gcd(LL a, LL b)
{
    if(b == 0LL) return a;
    return gcd(b, a % b);
}
LL bigmod(LL a, LL b, LL mod)
{
    if(b == 0LL) return 1LL;
    LL sq = bigmod(a, b/2LL, mod);
    sq = (sq * sq) % mod;
    if(b&1LL) return (sq * (a%mod)) % mod;
    return sq;
}
int h, w;
char maze[1002][1002];
int dp[1010][110][2];
#define INF 1000000
int visit(int i, int j, char prev)
{
  	if(i == h-1 && j == w-1) return (maze[i][j] == '#' && prev != '#');
    if(i >= h || j >= w) return INF;
    
    if(dp[i][j][(int)(prev == '#')] != -1) return dp[i][j][(int)(prev == '#')];
  
    int ans = visit(i, j+1, maze[i][j]) + (int) (maze[i][j] == '#' && prev != '#');
    ans = min(ans, visit(i + 1, j, maze[i][j]) + (int)(maze[i][j] == '#' && prev != '#'));
    return dp[i][j][(int)(prev == '#')] = ans;
}

int main()
{
    fasterIO
    cin >> h >> w;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < h; i++)
    {
        scanf("%s", maze[i]);
    }
    int ans = visit(0, 0, '.');
    cout << ans << endl;
    return 0;
}



