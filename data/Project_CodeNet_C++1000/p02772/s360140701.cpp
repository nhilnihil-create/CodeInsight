#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n;
	cin>>n;
	int k;
	bool ok = true;
	for (int i = 0; i<n; i++){
		cin>>k;
		if (k%3!=0 && k%5!=0 && k%2==0){
			ok = false;
		}
	}
	if (ok){
		cout<<"APPROVED";
	}
	else{
		cout<<"DENIED";
	}
	return 0;
}