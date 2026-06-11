#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
typedef vector<LL> 		VL;
#define si(n) cin>>n
#define dout(n) cout<<n<<"\n"
#define DRT() int t; si(t); while(t--)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//# define M_PI           3.14159265358979323846264338327950288
// DSU
void IO(){
	#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
	srand(chrono::steady_clock::now().time_since_epoch().count());
	off;
}

int main(){
	IO();
	LL w,h,x,y;
	cin>>w>>h>>x>>y;
	double area = (w*h)/2.0;
	cout<<area<<" ";
	LL a = w/2;
	LL b = h/2;
	LL r1 = w%2;
	LL r2 = h%2;
	if(!r1 && !r2 && a == x && b == y)
		cout<<1;
	else
		cout<<0;
	return 0;
}