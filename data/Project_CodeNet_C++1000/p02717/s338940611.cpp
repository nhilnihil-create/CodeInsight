#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[3];
	cin>>arr[0]>>arr[1]>>arr[2];
	swap(arr[0],arr[1]);
	swap(arr[0],arr[2]);
	for (int i = 0; i<3; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}