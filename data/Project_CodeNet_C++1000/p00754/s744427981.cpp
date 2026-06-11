#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define mp make_pair
#define fi first
#define sc second
char s[1000];
int main(){
	while(1) {
		fgets(s,500,stdin);
		int n = strlen(s);
		n--;
		if(n == 1 && s[0] == '.') {
			break;
		}


		stack<int> last;

		bool f = true;int rb = 0,sb = 0;
		REP(i,n) {
			if(!last.empty() && last.top() == 0 && s[i] == ']') {
				f = false;
				break;
			}
			if(!last.empty() && last.top() == 1 && s[i] == ')') {
				f = false;
				break;
			}
			if(s[i] == ')') {
				rb--;
				last.pop();
				if(rb < 0) {
					f = false;
					break;
				}
			}
			if(s[i] == ']') {
				sb--;
				last.pop();
				if(sb < 0) {
					f = false;
					break;
				}
			}
			if(s[i] == '(')  {
				rb++;
				last.push(0);
			}
			if(s[i] == '[')  {
				sb++;
				last.push(1);
			}
		}
		if(!last.empty()) {
			f = false;
		}
		if(f) {
			cout << "yes" << endl;
		}else {
			cout << "no" << endl;
		}
	}
	return 0;
}

