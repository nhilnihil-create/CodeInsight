#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int beki(int a,int b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


int gyakugen(int a){
	return beki(a,modulo-2);
}

int ans;
int n,a,b;

void decrease(int x){
	int t = 1;
	for(int i=0;i<x;i++){
		t = mod(t * (n-i));
		t = mod(t * gyakugen(i+1));
	}
	ans = mod(ans - t);
}

int main(){
	
	cin>>n>>a>>b;
	
	ans = beki(2,n);
	
	decrease(0);
	decrease(a);
	decrease(b);
	
	cout<<ans<<endl;
	
	return 0;
}
