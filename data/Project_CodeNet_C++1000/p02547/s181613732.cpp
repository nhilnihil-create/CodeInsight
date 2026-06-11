#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int streak=0;
	int ans=0;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(a==b)streak++;
		else {
			streak=0;
		}
		ans=max(ans,streak);
	}
	if(ans>=3)
	cout<<"Yes";
	else cout<<"No"; 
	return 0;
}