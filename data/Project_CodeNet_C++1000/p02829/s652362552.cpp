#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dob double
int main(){
	int a,b;
	cin>>a>>b;
	if (a + b == 3){
		cout<<3;
	}
	else if (a + b == 4){
		cout<<2;
	}
	else{
		cout<<1;
	}
	return 0;
}
