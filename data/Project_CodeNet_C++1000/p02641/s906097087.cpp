#include <bits/stdc++.h>
using namespace std;
int main(){
	int x, n;
	cin >> x >> n;
	if(n==0){
		cout << x;
		return 0;
	}
	int arr[n];
	for(int i=0; i<n; ++i){
		cin >> arr[i];
	}
	int a=x, pos;
	sort(arr, arr+n);
	for(int i=0; i<n; ++i){
		if(arr[i] <= x && (i==n-1 || arr[i+1]>x)){
			pos=i;
		}
	}
	for(int i=pos; i>=0; --i){
		if(arr[i] == a){
			a-=1;
		}
		else{
			break;
		}
	}
	int b=x;
	for(int i=pos; i<n; ++i){
		if(arr[i] == b){
			b+=1;
		}
		else{
			break;
		}
	}
	if(x-a<b-x){
		cout << a;
	}
	else if(b-x<x-a){
		cout << b;
	}
	else{
		cout << min(a,b);
	}
}
