#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, notSorted = 0;
	cin>>n;

	for(int i = 1; i <= n; i++){
		int num;
		cin>>num;
		if(num != i)
			notSorted++;
	}

	string s = notSorted < 3?"YES\n":"NO\n";
	cout<<s;
}