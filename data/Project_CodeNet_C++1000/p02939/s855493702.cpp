#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> pi;
typedef pair<int,int> vi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(vi c, vi d){
	return c.S < d.S;
}
	
	

int main() {
	string s, tmp, prev;
	cin >> s;
	int ans = 0;
	
	REP(i,0, (int)s.size()){
		if(i == 0){
			//++ans;
			prev = "";
			tmp = s[i];
			//cout << prev << endl;
		}
		else if(prev == tmp){
			tmp += s[i];
		}
		else{
			//cout << prev << endl;
			prev = tmp;
			tmp = s[i];
			++ans;
		}
	}
	
	cout << ans + (prev != tmp?1:0);
			
			
			

}
