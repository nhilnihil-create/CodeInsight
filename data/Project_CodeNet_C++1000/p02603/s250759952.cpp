#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	ll money = 1000;
	for(int i = 0;i < n;i++){
		int st = a[i];
		int now = a[i];
		int j = i;
		while(j < n && now <= a[j]){
			now = a[j];
			j++;
		}
		int end = a[j-1];
		money += (money / st) * end - money / st * st;
		i = j-1;
	}

	cout << money << endl;
}
