#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void input(){
	#ifndef ONLINE_JUDGE	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif
}
int main(){
	input();
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll arr[5];
	for(ll i=0;i<=4;i++){
		cin>>arr[i];
	}
	for(ll i=0;i<=5;i++){
		if(arr[i]==0){
			cout<<i+1<<endl;
			break;
		}
	}

}