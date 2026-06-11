#include<bits/stdc++.h>
using namespace std;
int main(){
	
		double h,b,sum=0,c;
		cin>>h>>b;
		for(int i=0;i<b;i++){
		    cin>>c;
		    sum+=c;
		}
		if(sum>=h){
		    cout<<"Yes";
		}
		else{
		    cout<<"No";
		}
	return 0;
}