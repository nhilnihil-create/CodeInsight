#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int N;
	cin>>N;
	
	string S;
	cin>>S;
	
	vector<int> d(2*N,1);
	if(S[0]=='W')d[0]=0;
	for(int i=1;i<2*N;i++){
		if(S[i]==S[i-1])d[i]=0;
		else d[i]=1;
	}
	
	int ans = 1;
	int l = 0;
	
	for(int i=0;i<2*N;i++){
		if(d[i]==0){
			ans = mod(ans * l);
			l--;
			if(i!=2*N-1)d[i+1]^=1;
		}
		else{
			l++;
		}
	}
	
	if(l!=0){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=1;i<=N;i++){
		ans = mod(ans * i);
	}
	
	cout<<ans<<endl;
	

    return 0;


}
