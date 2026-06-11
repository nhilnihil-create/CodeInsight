#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int p[n];
	for(int i=0; i<n; i++) cin >> p[i];
	int k = 0;
	for(int i=0; i<n; i++){
		if(p[i] != i+1)
			k++;
	}
	if(k<=2) cout << "YES";
	else cout << "NO";
	return 0;
}