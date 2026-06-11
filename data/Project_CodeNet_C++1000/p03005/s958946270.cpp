#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	int a,b;
	cin >> a >> b;

	if(b==1){
		cout << 0 << endl;
	}else{
		cout << a-b << endl;
	}

	return 0;
}
