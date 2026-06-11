#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m;
	int sum = 0;
	for (int i = 0; i<m; i++){
		cin>>k;
		sum+=k;
	}
	if (sum > n){
		cout<<-1;
	}
	else{
		cout<<n - sum;
	}
}