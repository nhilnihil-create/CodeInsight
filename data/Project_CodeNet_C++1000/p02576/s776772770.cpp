#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main(){
	int n,x,t;
	cin >> n >> x >> t;
	int sum=n/x;
	(n%x==0)?sum+=0:sum+=1;
	cout << sum*t << endl;
	return 0;
}