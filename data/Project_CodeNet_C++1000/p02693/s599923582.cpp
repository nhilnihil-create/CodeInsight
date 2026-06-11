#include<bits/stdc++.h>
using namespace std;
int main(){
        
	int k;
	cin>>k;
	int a,b;
	cin>>a>>b;
	if(a%k==0||b%k==0){
		cout<<"OK";
	}else{
		int n = a/k;
		int num = (n+1)*k;
		if(num<=b){
			cout<<"OK";
		}else{
			cout<<"NG";
		}
	}
}