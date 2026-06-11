#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll H, W; cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  rep(i, 0, H) {
  	rep(j, 0, W) {
    	cin >> grid[i][j];
    }
  }
  vector<vector<ll>> L(H, vector<ll>(W));
  vector<vector<ll>> R(H, vector<ll>(W));
  vector<vector<ll>> U(H, vector<ll>(W));
  vector<vector<ll>> D(H, vector<ll>(W));
  for(ll i = 0; i < H; i++) {
  	for(ll j = 0; j < W; j++) {
    	if (grid[i][j] == '#') {
        	L[i][j] = 0;
        } else if (j == 0) {
        	L[i][j] = 1;
        } else {
        	L[i][j] = L[i][j - 1] + 1;
        }
    }
  }
  for(ll i = 0; i < H; i++) {
  	for(ll j = W - 1; j >= 0; j--) {
    	if (grid[i][j] == '#') {
        	R[i][j] = 0;
        } else if (j == W - 1) {
        	R[i][j] = 1;
        } else {
        	R[i][j] = R[i][j + 1] + 1;
        }
    }
  }
  for(ll j = 0; j < W; j++) {
  	for(ll i = 0; i < H; i++) {
    	if (grid[i][j] == '#') {
        	D[i][j] = 0;
        } else if (i == 0) {
        	D[i][j] = 1;
        } else {
        	D[i][j] = D[i - 1][j] + 1;
        }
    }
  }
  for(ll j = 0; j < W; j++) {
  	for(ll i = H - 1; i >= 0; i--) {
    	if (grid[i][j] == '#') {
        	U[i][j] = 0;
        } else if (i == H - 1) {
        	U[i][j] = 1;
        } else {
        	U[i][j] = U[i + 1][j] + 1;
        }
    }
  }
  ll maxBright = 0;
  for(ll i = 0; i < H; i++) {
  	for(ll j = 0; j < W; j++) {
    	ll bright = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
      	if (maxBright < bright) maxBright = bright;
    }
  }
  cout << maxBright << endl;
}