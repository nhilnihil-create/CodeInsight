//69行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

//Simple Array Input
#define SAI int n;cin >> n;vi a(n);ain(a)
//Simple Graph Input
#define SGI(m) for(int i=0;i<m;i++){int a,b;cin >> a >> b;g[--a].pb(--b);g[b].pb(a);}
//Simple Tree Input
#define STI SGI(n-1)

typedef long long ll;
typedef long long integer;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){
    for(int i=0;i<a.size();i++)cout << a[i] << (i < a.size()-1 ? ' ' : '\n');
}
///////////////////////////////////////////////////////////


int main(void){
	int n,p;cin >> n >> p;
	ll mod = p;

	string s;cin >> s;

	reverse(s.begin(),s.end());

	if(p == 2){
        ll ans = 0;
        reverse(s.begin(),s.end());

        rep(i,n){
            if((s[i] - '0') % 2 == 0){
                ans += (ll)(i + 1);
            }
        }
        cout << ans << '\n';
        return 0;
	}else if(p == 5){
        ll ans = 0;
        reverse(s.begin(),s.end());

        rep(i,n){
            if((s[i] - '0') % 5 == 0){
                ans += (ll)(i + 1);
            }
        }
        cout << ans << '\n';
        return 0;
	}


	vector<ll> a(n);
	ll now = 1;
	rep(i,n){
		a[i] = (now * (s[i] - '0')) % mod;
		now = (now * 10LL) % mod;
	}		
	vector<ll> c(n+1,0);
	rep(i,n){
		c[i+1] = (c[i] + a[i]) % mod;
	}

	vector<ll> cnt(p+1,0);
	rep(i,n+1){
		cnt[c[i]]++;
	}
	ll ans = 0;
	rep(i,p){
		ll c = cnt[i];
		ans += c * (c - 1) / 2; 
	}
	cout << ans << '\n';
}