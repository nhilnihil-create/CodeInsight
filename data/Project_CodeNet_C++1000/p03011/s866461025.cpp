#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> dist(3);
	for(int i=0; i<3; i++){
		cin >> dist[i];
	}

	sort(dist.begin(), dist.end());

	int sum = dist[0] + dist[1];
	cout << sum << endl;

	return 0;
}