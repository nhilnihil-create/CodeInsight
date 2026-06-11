#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long h,w;
	cin>>h>>w;
	long long odd=0;
	long long even =0;
	if(h==1 || w==1){
		cout<<1<<"\n";
	}else{
	
		for(int i=0;i<w;i++){
			if(i%2==0){
				even+=1;
			}else{
				odd+=1;
			}
		}
		
		long long x=0;
		for(int i=0;i<h;i++){
			if(i%2==0){
				x+=even;
			}else{
				x+=odd;
			}
			
		}
		cout<<x<<"\n";
	}
 
	
	
	
	
	return 0;
}