#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define pb push_back
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ral;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		ral.pb(x);
	}
	sort(ral.begin(), ral.end());
	int temp, dis = 1000000000;
	for(int i=1; i<=100; i++){
		temp = 0;
		for(int j=0; j<n; j++){
			temp += (ral[j]-i)*(ral[j]-i);
		}
		dis = min(temp, dis);
		temp = 0;
	}
	cout << dis << endl;
	return 0;
}
