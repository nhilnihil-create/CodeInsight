#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>> a;
int main(){
	int n,k;
	cin>>n>>k;
	int sum=((n-1)*(n-2))/2;
	if(k>sum){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		a.push_back({1,i});
	}
	int now=2;
	while(sum>k){
		for(int i=now+1;i<=n;i++){
			if(sum>k) sum--,a.push_back({now,i});
			else break;
		}
		now++;
	}
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++){
		cout<<a[i].first<<" "<<a[i].second<<endl;
	}
}