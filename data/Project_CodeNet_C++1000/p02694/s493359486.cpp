#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int x;
	cin>>x;
	long long int day=0,bal=100;
	while(true){
		day++;
		bal+=bal/100;
		if(bal>=x){
			return cout<<day<<endl,0;
		}
	}
	return 0;
}
