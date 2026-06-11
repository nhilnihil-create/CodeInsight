#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int tot;
	bool flag = 0;
	for(int i=0;i<=x;i++){
		tot = 0;
		tot += i*2 + (x-i)*4;
		if(tot == y){
			cout<<"Yes"<<endl;
			flag = 1;
			break; 
		}
	}
	if(!flag) cout<<"No"<<endl;
	return 0;
} 