#include <bits/stdc++.h>
using namespace std;

int main() {
	int m,d;
	cin>>m>>d;
	if(d<22 || m<4){
		cout<<"0"<<endl;
		return 0;
	}
	int count=0;
	for(int i=22;i<=d;i++){
		if(i%10>=2 && i/10>=2){
			if(1<=(i%10)*(i/10) && (i%10)*(i/10)<=m){
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}