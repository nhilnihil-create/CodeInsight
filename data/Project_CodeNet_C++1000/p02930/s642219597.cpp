#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i) = (0);(i) < (n);++i)

int main(){
	int n;cin >> n;
	REP(i, n){
		REP(j, n){
			if(i >= j)continue;
			for(int k = 30;k >= 0;k--){
				if((i & (1 << k)) != (j & (1 << k))){
					cout << (k + 1) << " ";
					break;
				}
			}
			cout << endl;
		}
	}

	return 0;
}
