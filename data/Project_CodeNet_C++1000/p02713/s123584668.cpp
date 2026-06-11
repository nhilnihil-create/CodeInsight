#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(a<b) swap(a,b);
	while(b){
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}
int main(){
	int k;
	cin>>k;
	long long ret = 0;
	for(int i=1; i<=k; i++){
		for(int j=1; j<=k; j++){
			for (int r = 1; r<=k; r++){
				ret+=gcd(i,gcd(j,r));
			}
		}
	}
	cout<<ret;
}