#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, 	n)cin>>a[i];
	int ng = 0;
	int ok = 0;
	rep(i,n) ok = max(ok,a[i]);

	while(ok - ng > 1){
		int mid = ok + ng; mid /= 2;
		ll num = 0;
		rep(i,n){
			// a[i] に何回atkすれば全てmid以下になるか
			num += (mid - 1 + a[i]) / mid - 1;
		}
		if(num <= k) ok = mid;
		else ng = mid;
	} 
	cout << ok << endl;
}
