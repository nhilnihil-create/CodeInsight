#include <bits/stdc++.h>
using namespace std;
int main(){
	int num,leg;
	cin>>num>>leg;
	for(int i=0;i<=num;i++){
		int j=num-i,allf=i*2+j*4;
    	if(allf==leg){
    		cout<<"Yes"<<endl;
    		return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}