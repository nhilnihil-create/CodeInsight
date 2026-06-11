#include<bits/stdc++.h>
using namespace std;
long long p;
long long R[10005];
long long tenth[200005];

int main(){
	int len;
	cin>>len>>p;
	string s;
	cin>>s;
	if(p==2 || p==5){
		long long ret = 0;
		if(p==2){
			for(int i=0; s[i]; i++){
				int num = (int)(s[i]-'0');
				if(num%2==0) ret+=(i+1);
			}
		}
		if(p==5){
			for(int i=0; s[i]; i++){
				int num = (int)(s[i]-'0');
				if(num%5==0) ret+=(i+1);
			}
		}
		cout<<ret;
		return 0;
	}
	tenth[0] = 1;
	tenth[1] = 10%p;
	for(int i=2; i<=200000; i++){ //0이 i개일 때 p로 나눈 나머지 
		tenth[i] = (tenth[i-1]*10)%p; 
	}
	R[0] = 1;
	int curr = 0;
	for(int i=0; s[i]; i++){
		curr*=10;
		curr+=(int)(s[i]-'0');
		curr%=p;

		R[(curr*tenth[len-i-1])%p]++;
		
	}	
	long long ans = 0;
	
	for(int i=0; i<p; i++){
		ans+=R[i]*(R[i]-1)/2;
	}
	cout<<ans;
}