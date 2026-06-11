#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int x,y;
	int ans=0;
	cin>>x>>y;
	if(x==3){
		ans+=1;
	}else if(x==2){
		ans+=2;
	}else if(x==1){
		ans+=3;
	}
	if(y==3){
		ans+=1;
	}else if(y==2){
		ans+=2;
	}else if(y==1){
		ans+=3;
	}
	if(ans==6){
		ans+=4;
	}
	cout<<ans*100000<<endl;
	return 0;
}