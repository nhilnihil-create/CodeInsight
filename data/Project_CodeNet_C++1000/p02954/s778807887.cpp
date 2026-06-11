#include<bits/stdc++.h>
using namespace std;
char s[100005];
int before[100005];
int after[100005];
int counter[100005];

int main(){
	string ss;
	cin>>ss;
	int n = ss.length();
	for(int i=0; ss[i]; i++) s[i+1] = ss[i];
	for(int i=1; i<n; i++){
		if(s[i]=='R' && s[i+1]=='L'){
			before[i] = i;
			after[i] = i;
			before[i+1] = i+1;
			after[i+1] = i+1;
		}
	}
	after[n+1] = n+1;
	for(int i=1; i<=n; i++){
		if(!before[i]) before[i] = before[i-1];
	}
	for(int i=n; i>=1; i--){
		if(!after[i]) after[i] = after[i+1];
	}
	for(int i=1; i<=n; i++){
		if(s[i]=='R'){
			int go = after[i];
			if(go==n+1){
				counter[n]++;
				continue;
			}
			if((go-i)%2) counter[go+1]++;
			else counter[go]++;
		}
		else{
			int go = before[i];
			if(go==0){
				counter[1]++;
				continue;
			}
			if((i-go)%2) counter[go-1]++;
			else counter[go]++;
		}
	}
	for(int i=1; i<=n; i++) cout<<counter[i]<<" ";
}