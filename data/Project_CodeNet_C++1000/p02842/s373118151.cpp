#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int n;

	cin >> n;

	for(int i=0;i<=500000;i++){
		if(int(1.08*(double)i) == n){
			cout << i << endl;
			return 0;
		}
	}

	cout << ":(" << endl;
	

	return 0;
}
