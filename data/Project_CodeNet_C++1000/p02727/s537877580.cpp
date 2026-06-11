#include<bits/stdc++.h>
using namespace std;




int main(){

	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	vector<int> arr(a),brr(b),crr(c);
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	for(int i=0;i<b;i++){
		cin>>brr[i];
	}
	for(int i=0;i<c;i++){
		cin>>crr[i];
	}
	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());
	vector<int> ans;
	int cnt = 0;
	for(int i=a-1;i>=0;i--){
		if(cnt >= x)
			break;
		ans.push_back(arr[i]);
		cnt += 1;
	}
	cnt = 0;
	for(int i=b-1;i>=0;i--){
		if(cnt >= y)
			break;
		ans.push_back(brr[i]);
		cnt += 1;
	}
	for(int i=0;i<c;i++){
		ans.push_back(crr[i]);
	}
	sort(ans.begin(),ans.end());
	long long suma = 0;
	int n = ans.size();
	cnt = 0;
	for(int i=n-1;i>=0;i--){
		if(cnt >= x+y)
			break;
		suma += ans[i];
		cnt += 1;
	}
	cout<<suma<<endl;
	
	
	
	return 0;
  
}