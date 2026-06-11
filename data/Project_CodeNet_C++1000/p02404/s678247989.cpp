#include <iostream>
using namespace std;

void solve(int h,int w){
	int i,j;
	for(i=1;i<=w;i++){
		cout<<"#";
		if(i==w) cout<<endl;
	}
	for(j=1;j<=h-2;j++){
		for(i=1;i<=w;i++){
			if(i==1||i==w) cout<<"#";
			else cout<<".";
			if(i==w) cout<<endl;
		}
	}
	if(h!=1&&w!=1){
		for(i=1;i<=w;i++){
			cout<<"#";
			if(i==w) cout<<endl;
		}	
	}
	cout<<endl;
}

int main() {
	// your code goes here
	int h,w;
	cin>>h>>w;
	while(h!=0&&w!=0){
		solve(h,w);
		cin>>h>>w;
	}
	return 0;
}