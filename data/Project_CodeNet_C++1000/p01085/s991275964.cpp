#include "bits/stdc++.h"

#define REP(i, n ,N) for(int i = (n); i < (N); i++)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
using namespace std;
typedef long long ll;

int main(){
	while(1) {
		int m,nmin, nmax;
		cin >> m >> nmin >> nmax;
		if(m==0 && nmin==0 && nmax==0)break;
		int  max = 0, ans;
		vector<int> member(m + 1);
		REP(i,1,m+1){
			cin >> member[i];
		}

		REP(i, nmin, nmax + 1) {
			if (member[i] - member[i + 1] >= max) {
				max = member[i] - member[i + 1];
				ans = i;
			}
		}
		p(ans);
	}
	return 0;
}
