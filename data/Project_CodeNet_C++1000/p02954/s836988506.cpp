#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin>>s;
	int n=s.size();
	int dpr[n+1]={0};
	int dpl[n+1]={0};

	int rec=0;
	for(int i=1;i<=n;i++){
		dpr[i]=rec;
		if(s[i-1]=='R'){
			rec=i;
		}
	}
	rec=0;
	for(int i=n;i>=1;i--){
		dpl[i]=rec;
		if(s[i-1]=='L'){
			rec=i;
		}
	}

	int ans[n+1]={0};
	for(int i=1;i<=n;i++){
		if(s[i-1]=='L'){
			int tr=dpr[i];
			if(tr==0){
				continue;
			}
			if((i-tr)%2==1){
				ans[tr+1]++;
			}
			else{
				ans[tr]++;
			}
		}
		else{
			int tl=dpl[i];
			if(tl==0){
				continue;
			}
			if((tl-i)%2==1){
				ans[tl-1]++;
			}
			else{
				ans[tl]++;
			}
		}
	}	
	for(int  i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

        
	

	return 0;
}