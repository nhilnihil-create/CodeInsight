#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

const ll mod = 1e9 + 7;


main(){
	ll a,b,c;

	cin >> a >> b >> c;

	if(a+b<c && 4*a*b<(c-a-b)*(c-a-b)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
