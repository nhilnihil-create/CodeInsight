#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(200010);

	for (int i=0; i<n; i++) cin >> a[i];
	int first = 0;
	int second = 0;
	for (int i=0; i<n; i++){
		if(first < a[i]){
			second = first;
			first = a[i];
		}
		else if(second < a[i]){
			second = a[i];
		}
	}

	for(int i=0; i<n; i++){
		if (a[i] == first) cout << second << endl;
		else cout << first << endl;
	}
	return 0;
}