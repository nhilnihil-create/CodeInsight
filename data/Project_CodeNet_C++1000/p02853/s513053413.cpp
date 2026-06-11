#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int ans=0;
	if(a==1&&b==1){
		cout<<"1000000"<<endl;
		return 0;
	}
	switch(a){
		case 1:ans+=300000;break;
		case 2:ans+=200000;break;
		case 3:ans+=100000;break;
	}
	switch(b){
		case 1:ans+=300000;break;
		case 2:ans+=200000;break;
		case 3:ans+=100000;break;
	}
	cout<<ans<<endl;
	return 0;
}