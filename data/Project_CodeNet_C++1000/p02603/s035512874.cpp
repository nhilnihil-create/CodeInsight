#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long long now = 1000, cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > a[i + 1] || i + 1 == n){
			now += cnt * a[i];
			cnt = 0;
		}
		else if(a[i] < a[i + 1]){
			cnt += now / a[i];
			now -= (now / a[i]) * a[i];
		}
	}
	cout << now << endl;
	return 0;
}