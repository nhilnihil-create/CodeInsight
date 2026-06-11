#include <bits/stdc++.h>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int h,w,n;

	cin >> h >> w >> n;

	int d = max(h,w);

	if(n%d==0){
		cout << n / d << endl;
	}else{
		cout << n/d + 1 << endl;
	}

	return 0;
}