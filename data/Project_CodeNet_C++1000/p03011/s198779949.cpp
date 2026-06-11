#include <bits/stdc++.h>
using namespace std;

int main(){
	int p,q,r;
	cin>>p>>q>>r;
	vector<int> arr={p,q,r};
	sort(arr.begin(), arr.end());
	cout<<arr[0]+arr[1]<<endl;
}