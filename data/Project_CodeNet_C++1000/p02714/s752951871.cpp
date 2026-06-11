#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	vector<int >r(n+1,0),b(n+1,0),g(n+1,0);
	long long count=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='R')r[i]++;
		if(s[i-1]=='B')b[i]++;
		if(s[i-1]=='G')g[i]++;
		r[i]+=r[i-1];
		b[i]+=b[i-1];
		g[i]+=g[i-1];

	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			if(s[i-1]==s[j-1])continue;
			int k = 2*j-i;
			if(k>n){
				if(s[i-1]=='R'){
					if(s[j-1]=='G'){
						count+=(b[n]-b[j]);
				}
					else{
						count+=(g[n]-g[j]);
					}
				}
				else if(s[i-1]=='G'){
					if(s[j-1]=='R'){
						count+=(b[n]-b[j]);
					}
					else count+=(r[n]-r[j]);
				}
				else if(s[i-1]=='B'){
					if(s[j-1]=='G'){
						count+=(r[n]-r[j]);
					}
					else count+=(g[n]-g[j]);
				}
				//cout<<i<<' '<<j<<' '<<k<<' '<<count<<'\n';

				continue;
			}
			if(s[i-1]=='R'){
				if(s[j-1]=='G'){
					count+=(b[n]-b[k]+b[k-1]-b[j]);
				}
				else{
					count+=(g[n]-g[k]+g[k-1]-g[j]);
				}
			}
			else if(s[i-1]=='G'){
				if(s[j-1]=='R'){
					count+=(b[n]-b[k]+b[k-1]-b[j]);
				}
				else count+=(r[n]-r[k]+r[k-1]-r[j]);
			}
			else if(s[i-1]=='B'){
				if(s[j-1]=='G'){
					count+=(r[n]-r[k]+r[k-1]-r[j]);
				}
				else count+=(g[n]-g[k]+g[k-1]-g[j]);
			}
			//cout<<i<<' '<<j<<' '<<count<<'\n';
		}
	}
	cout<<count;
}