#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)
		cin >> v[i];
	ll result = 0;
	sort(v.begin(),v.end(),greater<int>());
	result += v[0];
	//cout << v[0] << endl;
	int flag = 0; int runs = 0;
	int i = 1;
	while(runs < n-2) {
		if(flag == 1)
		{
			result += v[i];
			i++;
			flag = 0;
		}
		else
		{
			result += v[i];
			flag = 1;
		}
		runs++;
	}
	cout << result << endl;
	return 0; 
}