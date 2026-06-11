#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	if (m == 1){
		cout<<n*(n-1)/2;
	}
	else{
		cout<< (n * (n-1)/2) + (m * (m-1)/2);
	}
}