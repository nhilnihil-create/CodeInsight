#include <bits/stdc++.h>
using namespace std;
int n,flag,x;
int main(){
	cin >> n ;
	flag = 0;
	for ( int i = 1 ; i <=  n; i ++ ){
		cin >> x ;
		if (x%2 == 0)
		if (x%3!=0&&x%5!=0) flag = 1;
	}
	if(flag) cout<<"DENIED"<<endl;
	else cout<<"APPROVED"<<endl;
	return 0;
}