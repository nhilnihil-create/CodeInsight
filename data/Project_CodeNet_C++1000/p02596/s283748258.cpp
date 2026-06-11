#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long int num,x=7,i=1,flag=0;
    cin>>num;
    
    if (num==1 || num==7){
    	cout<<1<<endl;
    	return 0;
	}
    if (num%2==0){
    	cout<<-1<<endl;
    	return 0;
	}
    for(i=1;i<=num;i++){
    	if (x%num==0){
    		cout<<i<<endl;
    		flag=1;
    		break;
		}
    	x=(x*10+7)%num;
	}
	if (flag==0){
		cout<<-1<<endl;
	}
	return 0;
}
