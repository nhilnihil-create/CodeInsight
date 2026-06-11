#include<iostream>

using namespace std;
int data[1001];
int main(){
	data[0]=0;
	for(int i=1;i<1001;i++)data[i]=data[i-1]+i;
	
	int n;
	while(cin>>n &&n){
		int now=1;
		int ans=0;
		for(int i=1;i<1001;){
			int tmp=data[now]-data[i-1];
			if(tmp<n)now++;
			else if(tmp>n)i++;
			else {
				ans++;
				i++;
			}
		}
		cout<<ans-1<<endl;
	}
}