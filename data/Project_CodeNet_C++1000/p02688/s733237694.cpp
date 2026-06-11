#include <bits/stdc++.h>
int arr[101];
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	int iter, var;
	for(int i=0; i<k; ++i){
		cin >> iter;
		for(int j=0; j<iter; ++j){
			cin >> var;
			arr[var]=1;
		}
	}
	int count=0;
	for(int i=1; i<=n; ++i){
		if(arr[i]!=1){
			count++;
		}
	}
	cout << count;
}
