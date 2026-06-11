
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define INF 1000000000

void boxSwap(int arr[]){
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;

	int boxes[3] = {x, y, z};
	boxSwap(boxes);
	for(int i=0; i < 3; i++){
		cout << boxes[i] << " ";
	}
	cout << endl;	
	return 0;
}
