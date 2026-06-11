#include<iostream>
using namespace std;

int main(){
	int n,k,q;
	cin>>n>>k>>q;
	int correct[n+1]={0};
	int total = q;
	while(q--){
		int a;
		cin>>a;
		correct[a]++;
	}
	for(int i=1; i<=n; i++){
		int score = k-(total-correct[i]);
		if(score<=0) cout<<"No"<<'\n';
		else cout<<"Yes"<<'\n';
	}
}
