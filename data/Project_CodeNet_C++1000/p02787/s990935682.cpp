#include <bits/stdc++.h>
using namespace std;

int H,K,damage[1001],price[1001],memo[10001];

void Input(){
	cin>>H>>K;
	for(int i=0; i<K; i++){
		cin>>damage[i]>>price[i];
	}
}

void dp(){
	for(int i=0; i<=H; i++){
		if(i==0){
			memo[0]=0;
		}else{
			int minim=1e9;
			for(int j=0; j<K; j++){
				if(i<damage[j]){
					minim=min(minim,price[j]);
				}else{
					minim=min(minim,price[j]+memo[i-damage[j]]);
				}
			}
			memo[i]=minim;
		}
	}
}

void Solve(){
	dp();
	cout<<memo[H]<<'\n';
}

int main(){
	Input();
	Solve();
}