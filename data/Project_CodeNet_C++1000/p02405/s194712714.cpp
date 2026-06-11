#include <bits/stdc++.h>
using namespace std;
int main(){
	while(1){
	int h,w,i,j;
	cin>>h>>w;
	if(h==0&&w==0) return 0;
	for(i=0;i<h;i++){
		if(i%2==0){
			for(j=0;j<w;j++){
				cout<<"#";
				j++;
				if(j==w) break;
				cout<<".";
			}
			cout<<"\n";
		}
		else{
			for(j=0;j<w;j++){
				cout<<".";
				j++;
				if(j==w) break;
				cout<<"#";
			}
			cout<<"\n";
		}
	}
	cout<<"\n";
	}
	return 0;
}