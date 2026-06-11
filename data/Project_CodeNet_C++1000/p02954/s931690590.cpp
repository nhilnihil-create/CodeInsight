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
	string s;
	cin >> s;
	int n = s.size();

	// LL を見つける
	vector<int> l(0) , r(0);
	rep(i,n){
		if((i == 0 || s[i] != s[i-1]) && s[i] == 'L'){
			l.push_back(i);
		}
		if((i == n - 1 ||  s[i] != s[i+1]) && s[i] == 'L'){
			l.push_back(i);
		}
		if((i == 0 || s[i] != s[i-1]) && s[i] == 'R'){
			r.push_back(i);
		}
		if((i == n - 1 ||  s[i] != s[i+1]) && s[i] == 'R'){
			r.push_back(i);
		}
	}

	vector<int> ans(n,0);
	rep(i,l.size()/2){
		int m = l[2*i];
		int M = l[2*i+1];
		int kazu = M - m + 1;
		int guu =(kazu+1) / 2;
		ans[m] = guu;
		ans[m-1] = kazu - guu;
	}
	rep(i,r.size()/2){
		int m = r[2*i];
		int M = r[2*i+1];
		int kazu = M - m + 1;
		int guu =(kazu+1) / 2;
		ans[M] += guu;
		ans[M+1] += kazu - guu;
	}

	for(auto x: ans){
		cout << x << " ";
	}
	cout << endl;
}
