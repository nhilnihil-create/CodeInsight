#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	int q;
	cin >> s >> q;
	string head = "", tail = "";
	bool rev = false;
	rep(i,q){
		int t;
		cin >> t;
		if(t == 1) rev = !rev;
		else{
			int f;
			char c;
			cin >> f >> c;
			if(f == 1){
				if(rev) tail += c;
				else head += c;
			}
			else{
				if(rev) head += c;
				else tail += c;
			}
		}
	}
	if(rev){
		for(int i = tail.size()-1; i >= 0; --i) cout << tail[i];
		for(int i = s.size()-1; i >= 0; --i) cout << s[i];
		for(int i = 0; i < head.size(); ++i) cout << head[i];
	}
	else{
		for(int i = head.size()-1; i >= 0; --i) cout << head[i];
		for(int i = 0; i < s.size(); ++i) cout << s[i];
		for(int i = 0; i < tail.size(); ++i) cout << tail[i];
	}
	cout << endl;
	return 0;
}
