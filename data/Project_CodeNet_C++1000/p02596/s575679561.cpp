#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
bool visited[1000007];
int main(){
	int k;
	cin>>k;
	int curr = 7%k;
	visited[7%k]=true;
	int rep = 1;
	while(1){
		if(curr==0){
			cout<<rep;
			return 0;
		}
		curr = (curr*10+7)%k;
		rep++;
		if(visited[curr]){
			cout<<-1;
			return 0;
		}
		visited[curr] = true;
	}
}