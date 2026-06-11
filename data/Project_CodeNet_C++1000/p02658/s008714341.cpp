#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	long long ans = 1, b = 1;
  	cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if(a[0] == 0){
		ans = 0;
	}else{
		for(int i=0;i<n;i++){
			b = ans;
			ans *= a[i];
			if(b > 1000000000000000000/a[i]){
				ans = -1;
			}
			if(ans == -1) break;
		}
	}
	cout<< ans<<endl;
}