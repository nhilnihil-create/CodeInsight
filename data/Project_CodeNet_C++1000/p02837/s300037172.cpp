#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int kind[20]={0};
	int unkind[20]={0};
	for(int i=0; i<n; i++){
		int q;
		cin>>q;
		while(q--){
			int a,b;
			cin>>a>>b;
			a--;
			if(b) kind[i]|=(1<<a);
			else unkind[i]|=(1<<a);
		}
	}
	int ret = 0;
	for(int state = 0; state<(1<<n); state++){
		int total_kind = 0;
		int total_unkind = 0;
		for(int j=0; j<n; j++){
			if(state&(1<<j)){
				total_kind|=(1<<j);
				total_kind|=kind[j];
				total_unkind|=unkind[j];
			}
		}
		bool possible = true;
		for(int j=0; j<n; j++){
			if((1<<j)&total_kind && (1<<j)&total_unkind) possible = false;
		}
		if(state^total_kind) possible = false;
		if(possible) ret = max(ret,__builtin_popcount(state));
	}
	cout<<ret;
}