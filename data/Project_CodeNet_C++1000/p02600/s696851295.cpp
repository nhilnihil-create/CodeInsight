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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int X; cin >> X;
	if(400 <= X && X <= 599){
		cout << 8 << '\n';
	}else if(600 <= X && X <= 799){
		cout << 7 << '\n';
	}else if(800 <= X && X <= 999){
		cout << 6 << '\n';
	}else if(1000 <= X && X <= 1199){
		cout << 5 << '\n';
	}else if(1200 <= X && X <= 1399){
		cout << 4 << '\n';
	}else if(1400 <= X && X <= 1599){
		cout << 3 << '\n';
	}else if(1600 <= X && X <= 1799){
		cout << 2 << '\n';
	}else if(1800 <= X && X <= 1999){
		cout << 1 << '\n';
	}
	
	return 0;
}
/*
__builtin_mul_overflow(x,y,&x)
-fsplit-stack
*/
