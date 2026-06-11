#include<bits/stdc++.h>

using namespace std;

int main(){
	int n , x;
	cin >> n >> x ;
	int arr[n];
	for(int i = 0 ;  i < n ; i++)
		cin >> arr[i];
	vector<int> d(n+1,0);
	d[0] = 0 ;
	for(int i = 0 ; i < n ; i+=1)
		d[i+1] = arr[i]+d[i];



	int ans = lower_bound(d.begin(),d.end(),x)-d.begin();
	if(d[ans] == x)
		ans++;
	cout << ans << endl;

}