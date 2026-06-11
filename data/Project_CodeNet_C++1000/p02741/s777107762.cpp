#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define all(x)        (x).begin(),(x).end()
#define mp            make_pair
#define pb            push_back
#define fi            first
#define se            second
#define sz(x)         ((int)(x).size())
#define rep(x,y,z)    for(int x=y;x<z;x++)
#define per(x,z,y)    for(int x=z-1;x>=y;x--)
#define trav(y,x)     for(auto& y:x)
#define pii           pair<int,int>
#define vi            vector<int>

int dbg = 0;
#define cri           if(0)
#define shame         cri cerr<<(++dbg)<<"\n\n";

// aaaaaaaaaaaaaaaa
const int N = 2e5 + 1;
const int lg = 20;
const ll mod = 0xfffff;

int ar[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
void solve() {
  int k; cin >> k;
  cout << ar[--k] << "\n";
}

int main() {
  // freopen("input.in", "r", stdin);
  // freopen("input.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// cout<<setprecision(15);
	// int t; cin>>t; while(t--)
	solve();
	return 0;
}