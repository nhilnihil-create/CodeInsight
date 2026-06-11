#include<bits/stdc++.h>
using namespace std;
bool visited[200005];
int arr[200005];
int main(){
	long long k;
	int n;
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>arr[i];
	vector<int>travel;
	int curr = 1;
	while(!visited[curr]){
		visited[curr] = true;
		travel.push_back(curr);
		curr = arr[curr];
	}
	int cycle_start;
	for(int i=0; i<travel.size(); i++){
		if(travel[i]==curr){
			cycle_start = i;
			break;
		}
	}
	if(k<=cycle_start) cout<<travel[k];
	else{
		k-=cycle_start;
		int cycle_len = travel.size()-cycle_start;
		k%=cycle_len;
		cout<<travel[cycle_start+k];
	}
}