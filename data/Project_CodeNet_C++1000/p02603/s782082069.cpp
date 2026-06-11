#include<iostream>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	ll m = 1000;
	int mn = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]<=mn)
			mn = arr[i];
		else{
			ll candy = m/mn;
			m%=mn;
			m+=candy*arr[i];
			mn = arr[i];
		}
	}
	cout<<m;
	return 0;
}
