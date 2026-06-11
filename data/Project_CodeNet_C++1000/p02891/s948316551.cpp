#include<bits/stdc++.h>
using namespace std;
#define int long long
char S[105];int K,las=1;
vector<int> vec;
signed main(){
	cin>>(S+1)>>K;
	int n=strlen(S+1);
	if(n==1) return cout<<n*K/2,0;
	for(int i=2;i<=n;++i)
		if(S[i]!=S[i-1]) vec.push_back(i-las),las=i;
		else if(i==n) vec.push_back(i-las+1);
	//for(auto v:vec) cout<<v<<endl;
	if(vec.size()==1) return cout<<n*K/2,0;
	if(S[1]==S[n]){
		int ans=0;
		for(int i=1;i<vec.size()-1;++i)
			ans+=vec[i]/2;ans*=K;
		ans+=(vec.front()+vec.back())/2*(K-1);
		ans+=vec.front()/2+vec.back()/2;
		cout<<ans;
	}
	else{
		int ans=0;
		for(auto v:vec)
			ans+=v/2*K;
		cout<<ans;
	}
	return 0;
} 