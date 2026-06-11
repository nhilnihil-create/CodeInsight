#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<pair<int,int> >arr;
	for(int i=1; i<=n; i++){
		int a;
		cin>>a;
		arr.push_back(make_pair(a,i));	
	}
	sort(arr.begin(),arr.end());
	for(int i=0; i<arr.size(); i++) cout<<arr[i].second<<" ";
}
