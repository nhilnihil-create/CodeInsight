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
	cin >> s;
	string head = "", tail = "";
	bool rev = false;
	int q;
	cin >> q;
	rep(qi,q){
		int t;
		cin >> t;
		if(t == 1) rev = !rev;
		else{
			int f;
			char c;
			cin >> f >> c;
			if(f == 1){
				if(!rev) head += c;
				else tail += c;
			}
			else{
				if(!rev) tail += c;
				else head += c;
			}
		}
	}
	if(!rev){
		for(int i = head.size()-1; i >= 0; --i) cout << head[i];
		cout << s << tail << endl;
	}
	else{
		for(int i = tail.size()-1; i >= 0; --i) cout << tail[i];
		for(int i = s.size()-1; i >= 0; --i) cout << s[i];
		cout << head << endl;
	}
	return 0;
}