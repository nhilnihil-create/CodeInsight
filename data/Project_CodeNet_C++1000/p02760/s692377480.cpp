#include <bits/stdc++.h>
using namespace std;

int main(void){
	vector<int> a(9);
	int n;
	for(int i = 0; i < 9; i++) cin >> a[i];
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i : b){
		for(int j = 0; j < 9; j++){
			if(i == a[j]){
				a[j] = -1;
			}
		}
	}
	string ans = "No";
	if(a[0] == -1 && a[1] == -1 && a[2] == -1) ans = "Yes";
	if(a[3] == -1 && a[4] == -1 && a[5] == -1) ans = "Yes";
	if(a[6] == -1 && a[7] == -1 && a[8] == -1) ans = "Yes";
	if(a[0] == -1 && a[3] == -1 && a[6] == -1) ans = "Yes";
	if(a[1] == -1 && a[4] == -1 && a[7] == -1) ans = "Yes";
	if(a[2] == -1 && a[5] == -1 && a[8] == -1) ans = "Yes";
	if(a[0] == -1 && a[4] == -1 && a[8] == -1) ans = "Yes";
	if(a[2] == -1 && a[4] == -1 && a[6] == -1) ans = "Yes";
	cout << ans << endl;
	return 0;
}
