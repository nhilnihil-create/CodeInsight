#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int n,k;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	
	int hano = (n-1)*(n-2)/2;
	if(k > hano){
		cout<<-1;
		return 0;
	}
	
	vector<pair<int,int> > v;
	for(int i=1;i<n;i++){
		v.push_back({i,n});
	}
	
	int x = 1,y = 2;
	while(hano > k){
		hano--;
		v.push_back({x,y});
		y++;
		if(y == n){
			x++;
			y = x+1;
		}
	}
	
	cout<<v.size()<<endl;
	for(auto p:v){
		cout<<p.first<<" "<<p.second<<endl;
	}
	
	return 0;
}
