#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int freq[n+1] = {0};
	for(int i=1; i<=n-1; i++){
		int num; cin >> num;
		freq[num]++;
	}
	for(int i=1; i<=n; i++) cout << freq[i] << endl;
	return 0;
}