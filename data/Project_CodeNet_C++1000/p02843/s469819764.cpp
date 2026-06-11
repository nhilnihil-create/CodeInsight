#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;

bool ans[200001];

main(){
	int x;
	cin >> x;

	for(int i=100;i<106;i++){
		ans[i] = true;
		int t = 0;
		for(int t=0;t<101001;t++){
			if(ans[t]) ans[t+i] = true;
		}
	}

	if(ans[x]){
		cout << 1 << endl;
	}else{
		cout << 0 << endl;
	}

	return 0;
}
