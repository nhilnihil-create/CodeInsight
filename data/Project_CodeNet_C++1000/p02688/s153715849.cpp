#include <iostream>
using namespace std;
int main(){
	int n, k,d,a,ans=0,list[1010];
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> d;
		for (int j = 0; j < d; j++) {
			cin >> a;
			list[a] = a;
		}
	}
	for (int i = 1; i <= n; i++)
		if (list[i] != i)
			ans++;
	cout << ans;
}