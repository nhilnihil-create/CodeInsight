#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int N;
	cin>>N;
	string S;
	cin>>S;
	

	
	int l = 0;
	int ans = 1;
	for(int i=0;i<S.size();i++){
		for(int j=0;j<l%2;j++){
			if(S[i]=='B')S[i]='W';
			else S[i]='B';
		}
		
		
		if(S[i]=='B'){
			l++;
		}
		else{
			ans = mod(ans * l);
			l--;	
		}
	}
	if(l!=0)ans = 0;
	
	for(int i=0;i<N;i++){
		ans = mod(ans * (i+1));
	}
	
	cout<<ans<<endl;
	
	return 0;
}
