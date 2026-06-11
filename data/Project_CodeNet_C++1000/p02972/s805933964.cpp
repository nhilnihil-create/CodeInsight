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
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)cin>>a[i];

	int cnt = 0;
	vector<int> ans(0);
	for(int i = n - 1; i >= 0; i--){
		if(a[i] % 2){
			cnt++;
			ans.push_back(i+1);

			int num = i + 1;
			for(int j = 1; j * j <= num; j++){
				if(num % j == 0){
					a[j-1]++;
					int neko = num / j;
					if(j * j != num)a[neko-1]++;
				}
			}
		}
	}
	SORT(ans);
	cout << cnt << endl;
	rep(i,cnt) cout << ans[i] << endl;
}
