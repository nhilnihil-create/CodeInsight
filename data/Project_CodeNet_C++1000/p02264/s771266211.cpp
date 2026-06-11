#include<bits/stdc++.h>
using namespace std;
struct pro{string x;int y;};
int i = 0,teil;
int main(){
	int n,time = 0,rim;
	cin>>n>>rim;
	teil = n;
	pro aho[n+1] ={};
	for(int i = 0;i<n;i++){
		cin>>aho[i].x>>aho[i].y;
	}
	int i = 0;
	while(i != teil){
		if(aho[i].y >rim){
			time += rim;
			aho[i].y -= rim;
			aho[teil] = aho[i];
			if(teil == n){
				teil = 0;
				i++;
			}
			else if(i == n){
				teil++;
				i = 0;
			}
			else{
				i++;
				teil++;
			}
			
		}
		else if(aho[i].y<=rim){
			time += aho[i].y;
			aho[i].y = time;
			cout<<aho[i].x<<" "<<aho[i].y<<endl;
			if(i == n){
				i = 0;
			}
			else{
				i++;
			}
		}
		
	}
}	
