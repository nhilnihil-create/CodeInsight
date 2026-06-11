#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	int i,k;
	int ans=1e9;
	int ctr=0;
	string S,T;

	cin >> S >> T;

	for(i=0;i<=(S.size()-T.size());i++){
		ctr=0;
		for(k=0;k<T.size();k++){
			if(S[i+k]!=T[k]) ctr++;
		}

		if(ctr<ans) ans=ctr;
	}
	
	cout << ans << endl;

	return 0;
}

