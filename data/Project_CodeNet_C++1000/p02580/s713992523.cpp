#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int h,w,m;
set<pi>mp;
int count_x[300005];
int count_y[300005];
int main(){
	cin>>h>>w>>m;
	while(m--){
		int y,x;
		cin>>y>>x;
		count_x[x]++;
		count_y[y]++;
		mp.insert(make_pair(y,x));
	}
	vector<int>arr;
	vector<int>brr;
	int mx = 0;
	for(int i=1; i<=h; i++) mx = max(mx,count_y[i]);
	for(int i=1; i<=h; i++) if(count_y[i]==mx) arr.push_back(i);
	mx = 0;
	for(int i=1; i<=w; i++) mx = max(mx,count_x[i]);
	for(int i=1; i<=w; i++) if(count_x[i]==mx) brr.push_back(i);
	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<brr.size(); j++){
			if(mp.find(pi(arr[i],brr[j]))==mp.end()){
				cout<<count_y[arr[i]]+count_x[brr[j]];
				return 0;
			}
		}
	}
	cout<<count_y[arr[0]]+count_x[brr[0]]-1;
}