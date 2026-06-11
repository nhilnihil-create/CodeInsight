#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;

const int N = 200005;
const int INF = 100000000;
int n,m;
string s;

int dst[N];
bool vstd[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	
	reverse(s.begin(),s.end());
	
	for(int i=0;i<n+1;i++){
		if(s[i] == '1'){
			vstd[i] = true;
			dst[i] = INF;
		}
	}
	
	priority_queue<pair<int,int> > pq;
	pq.push({0,0});
	dst[0] = 0;
	for(int i=1;i<=n;i++){
		if( i - m - 1 >= 0 ){
			vstd[i-m-1] = true;
		}
		if(vstd[i]){
			continue;
		}
		while(!pq.empty() && vstd[pq.top().second])pq.pop();
		if(pq.empty()){
			dst[i] = INF;
			continue;
		}
		dst[i] = -pq.top().first + 1;
		pq.push({-dst[i],i});
	}
	
	if(dst[n] == INF){
		cout<<-1;
		return 0;
	}
	/*
	for(int i=0;i<=n;i++){
		cout<<dst[i]<<" ";
	}cout<<endl;
	*/
	vector<int> sol;
	sol.clear();
	int lst = dst[n],idx = n;
	for(int i=n;i>=0;i--){
		if(dst[i] < lst){
			sol.push_back(idx-i);
			lst = dst[i];
			idx = i;
		}
	}
	
	//reverse(sol.begin(),sol.end());
	for(int x: sol){
		cout<<x<<" ";
	}
	
	return 0;
}
