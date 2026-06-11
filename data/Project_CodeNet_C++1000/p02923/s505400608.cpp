#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	int curr = 0; int mx = 0; int i=0;
	while(i<n-1){
		if(a[i]>=a[i+1]){
			curr++;
			mx = max(mx,curr);
		}
		else{
			curr=0;
		}
		i++;
	}
	cout << mx;
	
	return 0;
}