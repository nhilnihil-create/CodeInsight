#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int n1,n2;
	if (a%d == 0){
		n1 = a/d;
	}
	else{
		n1 = a/d + 1;
	}
	if (c%b == 0){
		n2 = c/b;
	}
	else{
		n2 = c/b + 1;
	}
	if (n1 >= n2){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}