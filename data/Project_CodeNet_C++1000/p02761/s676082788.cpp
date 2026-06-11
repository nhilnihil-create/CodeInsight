#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
int main(){
	int n,m;
	cin>>n>>m;
	vector<pi>arr(m);
	for(int i=0; i<m; i++) cin>>arr[i].first>>arr[i].second;
	if(n==1){
		for(int i=0; i<10; i++){
			int number[2]={0};
			number[1] = i;
			bool possible = true;
			for(int j=0; j<m; j++){
				if(number[arr[j].first]!=arr[j].second) possible = false;
			}
			if(possible){
				cout<<i;
				return 0;
			}
		}
	}
	else if(n==2){
		for(int i=10; i<100; i++){
			int number[3]={0};
			number[1] = i/10;
			number[2] = i%10;
			bool possible = true;
			for(int j=0; j<m; j++){
				if(number[arr[j].first]!=arr[j].second) possible = false;
			}
			if(possible){
				cout<<i;
				return 0;
			}
		}
	}
	else{
		for(int i=100; i<1000; i++){
			int number[4]={0};
			number[1] = i/100;
			number[3] = i%10;
			number[2] = (i/10)%10;
			bool possible = true;
			for(int j=0; j<m; j++){
				if(number[arr[j].first]!=arr[j].second) possible = false;
			}
			if(possible){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<-1;
}