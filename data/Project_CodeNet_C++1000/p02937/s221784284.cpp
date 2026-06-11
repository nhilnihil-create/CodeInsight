#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N = 1e5 + 5;
int nxt[N][26];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s,t;
	cin >> s >> t;
	rep(i,0,26)nxt[s.length()][i] = -1;
	for(int i = int(s.length()) - 1;i >= 0;--i){
		rep(c,0,26)nxt[i][c] = nxt[i+1][c];
		nxt[i][s[i] - 'a'] = i;
	}
	ll ind = 0;
	int sind = 0,tind=0;
	while(tind < t.length()){
		int nx = nxt[sind][t[tind] - 'a'];
		if(nx == -1){
			if(sind == 0){
				ind = -1;
				break;
			}
			ind += s.length() - sind;
			sind = 0;
		}
		else{
			ind += nx - sind + 1;
			sind = (nx+1) %(s.length());
			++tind;
		}
	}
	cout << ind << '\n';
}
