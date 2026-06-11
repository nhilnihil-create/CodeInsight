#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line

int main()
{
//すごろく
	int n , m ;
	cin >> n >> m ;
	string s ;
	cin >> s ;
	rSORT(s);
	vector<int> ans(0); //こいつをリバースシテ最終的に出力
	int now = 0 ;
	while(1){
		for(int i = m ; i >= 0 ; i--){
			if(now + i > n ) continue;
			if(i==0){
				puts("-1");
				return 0 ;
			}
			if(s[now+i] =='0'){
				//ok
				now += i; 
				ans.push_back(i);
				break;
			}
		}
		if(now==n) break;
	}
	rSORT(ans);
	for(auto x: ans){
		cout << x << " " ;
	}cout << endl;
}
