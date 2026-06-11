#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define si cout << "Yes\n";
#define no cout << "No\n";
int solve(int r,int g,int b,int k){
	if(g > r && b > g)return 1;
	if(!k)return 0;
	int res = 0;
	res |= solve(r*2,g,b,k-1);
	res |= solve(r,g*2,b,k-1);
	res |= solve(r,g,b*2,k-1);
	return res;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r,g,b,k; cin >> r >> g >> b >> k;
	int res = solve(r,g,b,k);
	if(res){
		si;
		return 0;
	}
	no;
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
