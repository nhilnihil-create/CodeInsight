#include<iostream>
#define max 246913 
using namespace std;

int main(){
	int n,ans;
	int N[max]={};
	int i,j;
	
	for(i = 2 ; i < max ; i++){
		if(N[i]==0){
			for(j = 2*i ; j < max ; j+=i){
				N[j]=1;
			}
		}
	}
	
	while(1){
		ans = 0;
		cin >> n;
		if(n==0){
			break;
		}
		for(i = n+1 ; i <= 2*n ; i++){
			if(N[i]==0){
				ans++;
			}
		}
		
		if(n==1){
			cout << 1 << endl;
		}else{
			cout << ans << endl;
		}
	}
	return 0;
}