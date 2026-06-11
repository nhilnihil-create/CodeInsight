#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll


main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	if(d<=a){
		cout << d << endl;
	}else if(d<=a+b){
		cout << a << endl;
	}else{
		cout << a - (d-a-b) << endl;
	}

	return 0;
}
