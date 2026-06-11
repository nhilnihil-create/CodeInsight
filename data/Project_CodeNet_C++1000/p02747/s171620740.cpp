#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i =(b)-1;i>=(a);--i)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 10;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	if(sz(s) & 1){
		cout << "No";
		return 0;
	}
	else{
		rep(i,0,sz(s)){
			if(s[i] != (i&1 ? 'i' : 'h')){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
