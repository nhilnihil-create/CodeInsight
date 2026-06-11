//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

string s;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	if (s.size() == 1){
		cout << (s[0] == '?'?'D':s[0]);
		return 0;
	}
	for (int i = 0; i < s.size(); i++){
		if (i == 0){
			if (s[i] == '?'){
				if (s[i + 1] == 'D' || s[i + 1] == '?'){
					s[i] = 'P';
				}else s[i] = 'D';
			}
		}else{
			if (s[i] == '?'){
				if (s[i - 1] == 'P') s[i] = 'D';
				else{
					if (i == s.size() - 1) s[i] = 'D';
					else if(s[i + 1] == 'D' || s[i + 1] == '?') s[i] = 'P';
					else s[i] = 'D';
				}
			}
		}
			
	}
	cout << s;











	return 0;
}
