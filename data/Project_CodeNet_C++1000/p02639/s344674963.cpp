#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[5],ans=0;
	for(int i=0;i<5;i++)cin>>arr[i];
   	for(int i=0;i<5;i++){
    	if(arr[i]==0){
    		ans=i+1;
    		break;
    	}
	}
	cout<<ans<<endl;
	return 0;
}