#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	int t = c/b;
	if(c%b>0) t++;
	int u = a/d;
	if(a%d>0) u++;

	if(t<=u){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	

	return 0;
}
