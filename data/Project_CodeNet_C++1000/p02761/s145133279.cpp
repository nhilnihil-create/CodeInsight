#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n,m;
	int ans[10];
	for(int i=0;i<10;i++) ans[i] = -1;

	cin >> n >> m;
	int s,c;
	for(int i=0;i<m;i++){
		cin >> s >> c;
	
		if(ans[s-1]==-1 || ans[s-1]==c){
			ans[s-1] = c;
		}else{
			cout << -1 << endl;
			return 0;
		}
	}
	if(ans[0]==0){
		if(n==1){
			cout << 0 << endl;
		}else{
			cout << -1 << endl;
			return 0;
		}
	}else{
		for(int i=0;i<n;i++){
			if(ans[i]==-1 && i==0 && n>1) cout << 1;
			else if(ans[i]==-1) cout << 0;
			else cout << ans[i];
		}
		cout << endl;
	}
	
	return 0;
}
