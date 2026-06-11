#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

int d;
int c[26];
int s[365][26];
int t[365];

int last[26];

main(){
	cin >> d;
	for(int i=0;i<26;i++) cin >> c[i];
	for(int i=0;i<d;i++){
		for(int j=0;j<26;j++){
			cin >> s[i][j];
		}
	}
	for(int i=0;i<d;i++){
		cin >> t[i];
		t[i]--;
	}


	int ans = 0;
	for(int i=0;i<d;i++){
		int day = i+1;
		ans += s[i][t[i]];
		last[t[i]] = day;
		for(int j=0;j<26;j++){
			ans -= c[j] * (day-last[j]);
		}
		printf("%lld\n",ans);
	}
	

	return 0;
}
