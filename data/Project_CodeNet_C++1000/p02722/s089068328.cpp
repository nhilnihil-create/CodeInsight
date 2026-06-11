#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0)
typedef long long ll;
#define int ll
#define swap(x, y)((x)^=(y)^=(x)^=(y))
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> matrix;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(c) c.begin(),c.end()
#define mp make_pair
#define pb push_back
#define f first
#define tcase int _; cin>> _; for( ; _; --_)
#define s second
#define endl '\n'
const int MAX = 1e6+1;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double DEG = 180/PI;
const int MOD = 1e9+7;
int mod(int x, int m){ if(x >= 0) return x % m; if(-x < m) return m-(-x); return mod(x%m, m);}
int gcd (int a, int b) {while(b){a = mod(a, b); swap(a, b);} return a;}
int lcm (int a, int b) {return a / gcd(a, b) * b;}
int fexp(int base, int exp, int m){
	int total = 1;
	while(exp > 0){
		if(exp % 2 == 1){
			total = mod(((mod(total, m)) * (mod(base, m))), m);
			exp--;
		}
		base= mod((mod(base, m) * mod(base, m)), m);
		exp /= 2;
	}
	return mod(total, m);
}

set<int> s;

set<int> div(int n){
    set<int> ans;
    for(int i = 1; i*i <= n; ++i){
        if(n % i == 0){
            ans.insert(i);
            if(n / i != i) ans.insert(n / i);
        }
    }
    return ans;
}

void check1(set<int> div, int n){
    for(int i: div){
        int x = n;
        if(i == 1) continue;

        while(x >= i && x%i == 0) x/=i;
        if(x%i == 1) s.insert(i);
    }
}

void check2(set<int> div){
    for(int i: div) if(i != 1) s.insert(i);
}

void solve(){
    int n;
    cin>> n;
    
    check1(div(n), n);
    check2(div(n-1));
   

    cout<< s.size()<< endl;
}

int32_t main(){
	fastio;
	solve();
	return 0;
}

