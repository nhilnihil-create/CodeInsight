#include<bits/stdc++.h>

#define int long long

using namespace std;

signed main(){
//	int t;
//	cin >> t;
//	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int amt=1000;
		int stk=0;
		int i=0;
		while(i<n){
			while(i<n-1&&a[i]>=a[i+1]){
				i++;
			}
			if(i==n-1){
				break;
			}
			stk+=(amt/a[i]);
			amt=amt%a[i];
			i++;
			while(i<n&&a[i-1]<=a[i]){
				i++;
			}
			amt+=(stk*a[i-1]);
			stk=0;
		}
		cout << amt << endl;
//	}
}