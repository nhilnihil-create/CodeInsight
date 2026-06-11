#include<bits/stdc++.h>
using namespace std;
int maxn = 1000000;
int fizzbuzz[1000007];

int main(){
	for(int i=3; i<=maxn; i+=3) fizzbuzz[i] = 1;
	for(int i=5; i<=maxn; i+=5){
		if(fizzbuzz[i]) fizzbuzz[i] = 3;
		else fizzbuzz[i] = 2;
	}	
	int n;
	cin>>n;
	long long ret = 0;
	for(int i=1; i<=n; i++){
		if(!fizzbuzz[i]) ret+=i;
	}
	cout<<ret;
}