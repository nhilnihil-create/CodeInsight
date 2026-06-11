#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int i, a, b;
	cin >> a >> b;
	if(a<b){
		for(i=1; i<=b; i++){
			cout << a;
		}
		cout << endl;
	}
	else{
		for(i=1; i<=a; i++){
			cout << b;
		}
		cout << endl;
	}
	 return 0;
 }
	
